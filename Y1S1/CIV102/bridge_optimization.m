clear;
close all;

% Parameter Initialization
bridge_length=1260;
number_bridge_check=2000;
bridge_distances=linspace(0,bridge_length,number_bridge_check);


train_total_weight=1000;
train_relative_distances=[52 228 392 568 732 908];
train_loads = [1 1 1 1 1 1] * train_total_weight/6;

number_train_locations=1000;
train_distances=linspace(-908,bridge_length-52,number_train_locations);

%Solving SFD

SFD=zeros(number_train_locations,number_bridge_check);
BMD=zeros(number_train_locations,number_bridge_check);

for i=1:number_train_locations
    train_absolute_distances=train_distances(i)+train_relative_distances;
    train_absolute_distances_opposite=bridge_length-train_absolute_distances;
    train_absolute_distances(train_absolute_distances<=0 | train_absolute_distances>=bridge_length)=0;
    train_absolute_distances_opposite(train_absolute_distances_opposite<=0 | train_absolute_distances_opposite>=bridge_length)=0;
    force_b=sum(train_loads.*train_absolute_distances)/bridge_length;
    force_a=sum(train_loads.*train_absolute_distances_opposite)/bridge_length;
    SFD(i,1)=force_a;
    SFD(i,number_bridge_check)=force_b;
    for j=2:number_bridge_check
        current_distance=bridge_distances(j);
        previous_distance=bridge_distances(j-1);
        SFD(i,j)=SFD(i,j)+SFD(i,j-1)-sum(train_loads(find(train_absolute_distances>previous_distance & train_absolute_distances<current_distance)));
        BMD(i,j)=BMD(i,j)+BMD(i,j-1)+SFD(i,j-1)*(current_distance-previous_distance);
    end    
end

for i=1:number_train_locations
    %plot(bridge_distances,SFD(i,:));
    %plot(bridge_distances,BMD(i,:));
end

max_SFD=max(abs(SFD));
max_BMD=max(abs(BMD));
%plot(bridge_distances,max_SFD);
%plot(bridge_distances,max_BMD);

%Bridge Parameters
% 1. Distance
% 2. Top Flange Width
% 3. Top Flange Thickness
% 4. Bottom Flange Width
% 5. Bottom Flange Thickness
% 6. Web Separation (Centre to Centre)
% 7. Web Length
% 8. Web Thickness
% 9. Top Glue Bend Width (Not Counting Web Thickness)
% 10. Top Glue Bend Thickness
% 11. Bottom Glue Bend Width (Not Counting Web Thickness)
% 12. Bottom Glue Bend Thickness

%Ideal
bridge_parameters=[0, 110, 2*1.27, 70, 1.27, 66, 99, 1.27, 8, 1.27, 8, 1.27;
bridge_length/8, 110, 2*1.27, 70, 1.27, 66, 99, 1.27, 8, 1.27, 8, 1.27;
bridge_length/8+1, 110, 5*1.27, 0, 1.27, 66, 95, 1.27, 8, 1.27, 0, 1.27;
7*bridge_length/8-1, 110, 5*1.27, 0, 1.27, 66, 95, 1.27, 8, 1.27, 0, 1.27;
7*bridge_length/8, 110, 2*1.27, 70, 1.27, 66, 99, 1.27, 8, 1.27, 8, 1.27;
bridge_length, 110, 2*1.27, 70, 1.27, 66, 99, 1.27, 8, 1.27, 8, 1.27];

%Budget (Maybe change edge thickness to 1?)
%Do we want to glue bottom, or simply bend matboard?        
bridge_parameters=[0, 110, 2*1.27, 70, 1.27, 66, 99, 1.27, 20, 1.27, 20, 1.27;
bridge_length/8, 110, 2*1.27, 70, 1.27, 66, 99, 1.27, 20, 1.27, 20, 1.27;
bridge_length/8+1, 110, 4*1.27, 0, 1.27, 66, 95, 1.27, 20, 1.27, 0, 1.27;
7*bridge_length/8-1, 110, 4*1.27, 0, 1.27, 66, 95, 1.27, 20, 1.27, 0, 1.27;
7*bridge_length/8, 110, 2*1.27, 70, 1.27, 66, 99, 1.27, 20, 1.27, 20, 1.27;
bridge_length, 110, 2*1.27, 70, 1.27, 66, 99, 1.27, 20, 1.27, 20, 1.27];

diaphragm_spacing_distance=ones(1,number_bridge_check)*200;

input_distance=bridge_distances;
top_flange_width = interp1(bridge_parameters(:, 1), bridge_parameters(:, 2), input_distance);
top_flange_thickness = interp1(bridge_parameters(:, 1), bridge_parameters(:, 3), input_distance);
bottom_flange_width = interp1(bridge_parameters(:, 1), bridge_parameters(:, 4), input_distance);
bottom_flange_thickness = interp1(bridge_parameters(:, 1), bridge_parameters(:, 5), input_distance);
web_separation = interp1(bridge_parameters(:, 1), bridge_parameters(:, 6), input_distance);
web_length = interp1(bridge_parameters(:, 1), bridge_parameters(:, 7), input_distance);
web_thickness = interp1(bridge_parameters(:, 1), bridge_parameters(:, 8), input_distance);
top_glue_bend_width = interp1(bridge_parameters(:, 1), bridge_parameters(:, 9), input_distance);
top_glue_bend_thickness = interp1(bridge_parameters(:, 1), bridge_parameters(:, 10), input_distance);
bottom_glue_bend_width = interp1(bridge_parameters(:, 1), bridge_parameters(:, 11), input_distance);
bottom_glue_bend_thickness = interp1(bridge_parameters(:, 1), bridge_parameters(:, 12), input_distance);


top_flange_area = top_flange_width .* top_flange_thickness;
top_flange_centroid_distance_bottom = bottom_flange_thickness + web_length + top_flange_thickness/2;
top_flange_second_moment_of_area = top_flange_width .* top_flange_thickness.^3 / 12;

bottom_flange_area = bottom_flange_width .* bottom_flange_thickness;
bottom_flange_centroid_distance_bottom = bottom_flange_thickness/2;
bottom_flange_second_moment_of_area = bottom_flange_width .* bottom_flange_thickness.^3 / 12;

webs_flange_area = 2 * web_thickness .* web_length;
webs_flange_centroid_distance_bottom = bottom_flange_thickness + web_length/2;
webs_flange_second_moment_of_area = 2 * web_thickness .* web_length.^3 / 12;

top_glue_bends_area = 2 * top_glue_bend_width .* top_glue_bend_thickness;
top_glue_bends_centroid_distance_bottom = bottom_flange_thickness + web_length - top_glue_bend_thickness/2;
top_glue_bends_second_moment_of_area = 2 * top_glue_bend_width .* top_glue_bend_thickness.^3 / 12;

bottom_glue_bends_area = 2 * bottom_glue_bend_width .* bottom_glue_bend_thickness;
bottom_glue_bends_centroid_distance_bottom = bottom_flange_thickness + top_glue_bend_thickness/2;
bottom_glue_bends_second_moment_of_area = 2 * bottom_glue_bend_width .* bottom_glue_bend_thickness.^3 / 12;

bridge_centroid_distance_bottom = (top_flange_area .* top_flange_centroid_distance_bottom + bottom_flange_area .* bottom_flange_centroid_distance_bottom + webs_flange_area .* webs_flange_centroid_distance_bottom + top_glue_bends_area .* top_glue_bends_centroid_distance_bottom + bottom_glue_bends_area .* bottom_glue_bends_centroid_distance_bottom) ./ (top_flange_area + bottom_flange_area + webs_flange_area + top_glue_bends_area + bottom_glue_bends_area);
bridge_centroid_distance_top = bottom_flange_thickness + web_length + top_flange_thickness - bridge_centroid_distance_bottom;
bridge_second_moment_of_area = top_flange_second_moment_of_area + bottom_flange_second_moment_of_area + webs_flange_second_moment_of_area + top_glue_bends_second_moment_of_area + bottom_glue_bends_second_moment_of_area + top_flange_area .* (top_flange_centroid_distance_bottom - bridge_centroid_distance_bottom).^2 + bottom_flange_area .* (bottom_flange_centroid_distance_bottom - bridge_centroid_distance_bottom).^2 + webs_flange_area .* (webs_flange_centroid_distance_bottom - bridge_centroid_distance_bottom).^2 + top_glue_bends_area .* (top_glue_bends_centroid_distance_bottom - bridge_centroid_distance_bottom).^2 + bottom_glue_bends_area .* (bottom_glue_bends_centroid_distance_bottom - bridge_centroid_distance_bottom).^2;

webs_flange_first_moment_of_area = bottom_flange_area .* (bridge_centroid_distance_bottom - bottom_flange_centroid_distance_bottom) + bottom_glue_bends_area .* (bridge_centroid_distance_bottom - bottom_glue_bends_centroid_distance_bottom) + ((bridge_centroid_distance_bottom - bottom_flange_thickness) ./ web_length .* webs_flange_area) .* (bottom_flange_thickness + (bridge_centroid_distance_bottom - bottom_flange_thickness)/2);
top_glue_bends_first_moment_of_area = top_flange_area .* (bridge_centroid_distance_top - top_flange_thickness/2);
bottom_glue_bends_first_moment_of_area = bottom_flange_area .* (bridge_centroid_distance_bottom - bottom_flange_centroid_distance_bottom);


top_flange_stress=max_BMD.*bridge_centroid_distance_top./bridge_second_moment_of_area;
bottom_flange_stress=max_BMD.*bridge_centroid_distance_bottom./bridge_second_moment_of_area;
webs_flange_shear_stress=max_SFD.*webs_flange_first_moment_of_area./bridge_second_moment_of_area./(2*web_thickness);
top_glue_shear_stress=max_SFD.*top_glue_bends_first_moment_of_area./bridge_second_moment_of_area./(2*(top_glue_bend_width+web_thickness));
bottom_glue_shear_stress=max_SFD.*bottom_glue_bends_first_moment_of_area./bridge_second_moment_of_area./(2*(bottom_glue_bend_width+web_thickness));


top_flange_compressive_failure_stress=ones(1,number_bridge_check)*6;
bottom_flange_tensile_failure_stress=ones(1,number_bridge_check)*30;
top_flange_between_compressive_buckling_stress=4*pi^2*4000/12/(1-(0.2)^2)*((web_thickness./(web_separation-web_thickness)).^2);
top_flange_tips_compressive_buckling_stress=0.425*pi^2*4000/12/(1-(0.2)^2)*((web_thickness./((top_flange_width-web_separation-web_thickness)/2)).^2);
webs_flange_compressive_buckling_stress=6*pi^2*4000/12/(1-(0.2)^2)*((web_thickness./bridge_centroid_distance_top).^2);

webs_flange_shear_failure_stress=ones(1,number_bridge_check)*4;
webs_flange_shear_buckling_stress=5*pi^2*4000/12/(1-(0.2)^2)*((web_thickness./(web_length)).^2+(web_thickness./diaphragm_spacing_distance).^2);
top_glue_shear_failure_stress=ones(1,number_bridge_check)*2;
bottom_glue_shear_failure_stress=ones(1,number_bridge_check)*2;


FOS_tensile=bottom_flange_tensile_failure_stress./bottom_flange_stress;
FOS_compressive=top_flange_compressive_failure_stress./top_flange_stress;
FOS_between_compressive_buckling=top_flange_between_compressive_buckling_stress./top_flange_stress;
FOS_tips_compressive_buckling=top_flange_tips_compressive_buckling_stress./top_flange_stress;
FOS_webs_flange_compressive_buckling=webs_flange_compressive_buckling_stress./top_flange_stress;
FOS_webs_shear=webs_flange_shear_failure_stress./webs_flange_shear_stress;
FOS_top_glue_shear=top_glue_shear_failure_stress./top_glue_shear_stress;
FOS_bottom_glue_shear=bottom_glue_shear_failure_stress./bottom_glue_shear_stress;
FOS_webs_shear_buckling=webs_flange_shear_buckling_stress./webs_flange_shear_stress;

moment_fail_tensile=FOS_tensile.*max_BMD;
moment_fail_compressive=FOS_compressive.*max_BMD;
moment_fail_between_compressive_buckling=FOS_between_compressive_buckling.*max_BMD;
moment_fail_tips_compressive_buckling=FOS_tips_compressive_buckling.*max_BMD;
moment_fail_webs_flange_compressive_buckling=FOS_webs_flange_compressive_buckling.*max_BMD;

shear_fail_webs_shear=FOS_webs_shear.*max_SFD;
shear_fail_top_glue_shear=FOS_top_glue_shear.*max_SFD;
shear_fail_bottom_glue_shear=FOS_bottom_glue_shear.*max_SFD;
shear_fail_webs_shear_buckling=FOS_webs_shear_buckling.*max_SFD;

figure;

% Subplot 1 - Shear Force Distribution (SFD)
subplot(1, 2, 1);
title('SFD');
hold on;

plot(bridge_distances, max_SFD, "-k", 'LineWidth', 2, 'DisplayName', 'Max SFD');
plot(bridge_distances, shear_fail_webs_shear, "--r", 'LineWidth', 2, 'DisplayName', 'Shear Fail Webs Shear');
plot(bridge_distances, shear_fail_top_glue_shear, "--y", 'LineWidth', 2, 'DisplayName', 'Shear Fail Top Glue Shear');
%plot(bridge_distances, shear_fail_bottom_glue_shear, "--g", 'LineWidth', 2, 'DisplayName', 'Shear Fail Bottom Glue Shear');
plot(bridge_distances, shear_fail_webs_shear_buckling, "--b", 'LineWidth', 2, 'DisplayName', 'Shear Fail Webs Shear Buckling');

legend('show');
xlabel('Bridge Distances');
ylabel('Shear Force');
grid on;

hold off;

% Subplot 2 - Bending Moment Distribution (BMD)
subplot(1, 2, 2);
title('BMD');
hold on;

plot(bridge_distances, max_BMD, "-k", 'LineWidth', 2, 'DisplayName', 'Max BMD');
plot(bridge_distances, moment_fail_tensile, "--r", 'LineWidth', 2, 'DisplayName', 'Moment Fail Tensile');
plot(bridge_distances, moment_fail_compressive, "--y", 'LineWidth', 2, 'DisplayName', 'Moment Fail Compressive');
plot(bridge_distances, moment_fail_between_compressive_buckling, "--g", 'LineWidth', 2, 'DisplayName', 'Moment Fail Between Compressive Buckling');
plot(bridge_distances, moment_fail_tips_compressive_buckling, "--b", 'LineWidth', 2, 'DisplayName', 'Moment Fail Tips Compressive Buckling');
%plot(bridge_distances, moment_fail_webs_flange_compressive_buckling, "--m", 'LineWidth', 2, 'DisplayName', 'Moment Fail Webs Flange Compressive Buckling');

legend('show');
xlabel('Bridge Distances');
ylabel('Bending Moment');
grid on;

hold off;
