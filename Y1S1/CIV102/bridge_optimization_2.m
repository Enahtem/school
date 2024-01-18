clear;
close all;

%%%%%%%%%%%%%%%%%%%%%%%%%%%
% PARAMETER INITIALIZATION
%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Length of the bridge
bridge_length=1260;

% Number of locations checked for internal forces on the bridge
number_bridge_check=2000; 

% Distances from left of bridge checked
bridge_distances=linspace(0,bridge_length,number_bridge_check); 

% Total weight of the train
train_total_weight=400;

% Distances of each train contact point from the train's left edge
train_relative_distances=[52 228 392 568 732 908];

% Load Case 1 weight distribution
train_loads = [1 1 1 1 1 1] * train_total_weight/6;

% Load Case 2 weight distribution
%train_loads = [1 1 1 1 1.35 1.35] * train_total_weight/6.7;

% Number of positions of train calculated for internal forces
number_train_locations=1000;
train_distances=linspace(-908,bridge_length-52,number_train_locations); % Distances of left edge of train from first load on left to last load on right

%%%%%%%%%%%%%%%%%%%%%%%%%%%
%SOLVING SFD AND BMD
%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Initializing SFD/BMD at all train locations, at all bridge points
SFD=zeros(number_train_locations,number_bridge_check);
BMD=zeros(number_train_locations,number_bridge_check);


% Looping across all train locations
for i=1:number_train_locations
    % Distance of train loads from left edge of bridge
    train_absolute_distances=train_distances(i)+train_relative_distances;
    % Distance of train loads from right edge of bridge
    train_absolute_distances_opposite=bridge_length-train_absolute_distances;
    % Removing all train load distances not on the bridge (past left or right edge)
    train_absolute_distances(train_absolute_distances<=0 | train_absolute_distances>=bridge_length)=0;
    train_absolute_distances_opposite(train_absolute_distances_opposite<=0 | train_absolute_distances_opposite>=bridge_length)=0;
    % Reaction force of right support from moment summation
    force_b=sum(train_loads.*train_absolute_distances)/bridge_length;
    % Reaction force of left support from moment summation
    force_a=sum(train_loads.*train_absolute_distances_opposite)/bridge_length;
    % Adding reaction forces to corresponding sections of SFD
    SFD(i,1)=force_a;
    SFD(i,number_bridge_check)=force_b;

    % Looping across all bridge locations (calculating SFD/BMD)
    for j=2:number_bridge_check
        % Finding distance bounds of sections being analyzed
        current_distance=bridge_distances(j);
        previous_distance=bridge_distances(j-1);
        % Setting SFD to be the sum of:
            % Existing reaction force, Shear from previous section, Train loads
        SFD(i,j)=SFD(i,j)+SFD(i,j-1)-sum(train_loads(find(train_absolute_distances>previous_distance & train_absolute_distances<current_distance)));
        % Setting BMD to be the sum of:
            % Moment from previous section, Shear*distance of section
        BMD(i,j)=BMD(i,j-1)+SFD(i,j-1)*(current_distance-previous_distance);
    end    
end




%SFD/BMD Envelopes (Maximum values at each measured point for whole train crossing)
max_SFD=max(abs(SFD));
max_BMD=max(abs(BMD));

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


% Design 0
bridge_parameters=[0, 100, 1.27, 80, 1.27, 80-1.27, 75-1.27, 1.27, 5, 1.27;
bridge_length, 100, 1.27, 80, 1.27, 80-1.27, 75-1.27, 1.27, 5, 1.27];

%Design 1
bridge_parameters=[0, 110, 3*1.27, 70+1.27, 1.27, 70, 75-1.27, 1.27, 5, 1.27;
bridge_length, 110, 3*1.27, 70+1.27, 1.27, 70, 75-1.27, 1.27, 5, 1.27];

%Design 2
bridge_parameters=[0, 110, 5*1.27, 70+1.27, 1.27, 70, 75-1.27, 1.27, 20, 1.27;
bridge_length, 110, 5*1.27, 70+1.27, 1.27, 70, 75-1.27, 1.27, 20, 1.27];

%Design 3
bridge_parameters=[0, 110, 3*1.27, 66+1.27, 1.27, 66, 75-1.27, 1.27, 20, 1.27;
bridge_length/8, 110, 3*1.27, 66+1.27, 1.27, 66, 75-1.27, 1.27, 20, 1.27;
bridge_length/8+1, 110, 5*1.27, 0, 0, 66, 75-1.27, 1.27, 20, 1.27;
7*bridge_length/8-1, 110, 5*1.27, 0, 0, 66, 75-1.27, 1.27, 20, 1.27;
7*bridge_length/8, 110, 3*1.27, 66+1.27, 1.27, 66, 75-1.27, 1.27, 20, 1.27;
bridge_length, 110, 3*1.27, 66+1.27, 1.27, 66, 75-1.27, 1.27, 20, 1.27];

% Design 4
bridge_parameters=[0, 110, 2*1.27, 66+1.27, 1.27, 66, 100-2*1.27-1.27, 1.27, 20, 1.27;
bridge_length/8, 110, 2*1.27, 66+1.27, 1.27, 66, 100-2*1.27-1.27, 1.27, 20, 1.27;
bridge_length/8+1, 110, 3*1.27, 0, 0, 66, 100-3*1.27, 1.27, 20, 1.27;
7*bridge_length/8-1, 110, 3*1.27, 0, 0, 66, 100-3*1.27, 1.27, 20, 1.27;
7*bridge_length/8, 110, 2*1.27, 66+1.27, 1.27, 66, 100-2*1.27-1.27, 1.27, 20, 1.27;
bridge_length, 110, 2*1.27, 66+1.27, 1.27, 66, 100-2*1.27-1.27, 1.27, 20, 1.27];

% Maximum distance between diaphragms
diaphragm_distance=200;
diaphragm_spacing_distance=ones(1,number_bridge_check)*diaphragm_distance;

%Interpolations of bridge parameters across bridge
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

% Top Flange Values
top_flange_area = top_flange_width .* top_flange_thickness;
top_flange_centroid_distance_bottom = bottom_flange_thickness + web_length + top_flange_thickness/2;
top_flange_second_moment_of_area = top_flange_width .* top_flange_thickness.^3 / 12;

% Bottom Flange Values
bottom_flange_area = bottom_flange_width .* bottom_flange_thickness;
bottom_flange_centroid_distance_bottom = bottom_flange_thickness/2;
bottom_flange_second_moment_of_area = bottom_flange_width .* bottom_flange_thickness.^3 / 12;

% Webs Flange Values
webs_flange_area = 2 * web_thickness .* web_length;
webs_flange_centroid_distance_bottom = bottom_flange_thickness + web_length/2;
webs_flange_second_moment_of_area = 2 * web_thickness .* web_length.^3 / 12;

% Top Glue Bends Values
top_glue_bends_area = 2 * top_glue_bend_width .* top_glue_bend_thickness;
top_glue_bends_centroid_distance_bottom = bottom_flange_thickness + web_length - top_glue_bend_thickness/2;
top_glue_bends_second_moment_of_area = 2 * top_glue_bend_width .* top_glue_bend_thickness.^3 / 12;

% Bridge cross sectional values
bridge_centroid_distance_bottom = (top_flange_area .* top_flange_centroid_distance_bottom + bottom_flange_area .* bottom_flange_centroid_distance_bottom + webs_flange_area .* webs_flange_centroid_distance_bottom + top_glue_bends_area .* top_glue_bends_centroid_distance_bottom) ./ (top_flange_area + bottom_flange_area + webs_flange_area + top_glue_bends_area);
bridge_centroid_distance_top = bottom_flange_thickness + web_length + top_flange_thickness - bridge_centroid_distance_bottom;
bridge_second_moment_of_area = top_flange_second_moment_of_area + bottom_flange_second_moment_of_area + webs_flange_second_moment_of_area + top_glue_bends_second_moment_of_area + top_flange_area .* (top_flange_centroid_distance_bottom - bridge_centroid_distance_bottom).^2 + bottom_flange_area .* (bottom_flange_centroid_distance_bottom - bridge_centroid_distance_bottom).^2 + webs_flange_area .* (webs_flange_centroid_distance_bottom - bridge_centroid_distance_bottom).^2 + top_glue_bends_area .* (top_glue_bends_centroid_distance_bottom - bridge_centroid_distance_bottom).^2;

% Bridge volume. INCLUDES SKETCHY CODE
bridge_cross_sectional_area=top_flange_area + bottom_flange_area + webs_flange_area + top_glue_bends_area;
number_diaphragms=9;
bridge_volume=sum(bridge_cross_sectional_area)*(bridge_distances(2)-bridge_distances(1))+number_diaphragms*(web_separation(1,1)-web_thickness(1,1)).*(web_length(1,1)); %Assumed constant web seperation/thickness/length for brevity
disp("Percent Matboard Used: "+bridge_volume/1.27/813/1016);


% First moments of area
webs_flange_first_moment_of_area = bottom_flange_area .* (bridge_centroid_distance_bottom - bottom_flange_centroid_distance_bottom) + ((bridge_centroid_distance_bottom - bottom_flange_thickness) ./ web_length .* webs_flange_area) .* (bottom_flange_thickness + (bridge_centroid_distance_bottom - bottom_flange_thickness)/2);
top_glue_bends_first_moment_of_area = top_flange_area .* (bridge_centroid_distance_top - top_flange_thickness/2);

% Maximum applied stresses
top_flange_stress=max_BMD.*bridge_centroid_distance_top./bridge_second_moment_of_area;
bottom_flange_stress=max_BMD.*bridge_centroid_distance_bottom./bridge_second_moment_of_area;
webs_flange_shear_stress=max_SFD.*webs_flange_first_moment_of_area./bridge_second_moment_of_area./(2*web_thickness);
top_glue_shear_stress=max_SFD.*top_glue_bends_first_moment_of_area./bridge_second_moment_of_area./(2*(top_glue_bend_width+web_thickness));

% Material capacities
top_flange_compressive_failure_stress=ones(1,number_bridge_check)*6;
bottom_flange_tensile_failure_stress=ones(1,number_bridge_check)*30;
top_flange_between_compressive_buckling_stress=4*pi^2*4000/12/(1-(0.2)^2)*((web_thickness./(web_separation-web_thickness)).^2);
top_flange_tips_compressive_buckling_stress=0.425*pi^2*4000/12/(1-(0.2)^2)*((web_thickness./((top_flange_width-web_separation-web_thickness)/2)).^2);
webs_flange_compressive_buckling_stress=6*pi^2*4000/12/(1-(0.2)^2)*((web_thickness./bridge_centroid_distance_top).^2);
webs_flange_shear_failure_stress=ones(1,number_bridge_check)*4;
webs_flange_shear_buckling_stress=5*pi^2*4000/12/(1-(0.2)^2)*((web_thickness./(bottom_flange_thickness + web_length + top_flange_thickness)).^2+(web_thickness./diaphragm_spacing_distance).^2);
top_glue_shear_failure_stress=ones(1,number_bridge_check)*2;

% Factors of Safety
FOS_tensile=bottom_flange_tensile_failure_stress./bottom_flange_stress;
FOS_compressive=top_flange_compressive_failure_stress./top_flange_stress;
FOS_between_compressive_buckling=top_flange_between_compressive_buckling_stress./top_flange_stress;
FOS_tips_compressive_buckling=top_flange_tips_compressive_buckling_stress./top_flange_stress;
FOS_webs_flange_compressive_buckling=webs_flange_compressive_buckling_stress./top_flange_stress;
FOS_webs_shear=webs_flange_shear_failure_stress./webs_flange_shear_stress;
FOS_top_glue_shear=top_glue_shear_failure_stress./top_glue_shear_stress;
FOS_webs_shear_buckling=webs_flange_shear_buckling_stress./webs_flange_shear_stress;

% Failing Moments
moment_fail_tensile=FOS_tensile.*max_BMD;
moment_fail_compressive=FOS_compressive.*max_BMD;
moment_fail_between_compressive_buckling=FOS_between_compressive_buckling.*max_BMD;
moment_fail_tips_compressive_buckling=FOS_tips_compressive_buckling.*max_BMD;
moment_fail_webs_flange_compressive_buckling=FOS_webs_flange_compressive_buckling.*max_BMD;

% Failing Shears
shear_fail_webs_shear=FOS_webs_shear.*max_SFD;
shear_fail_top_glue_shear=FOS_top_glue_shear.*max_SFD;
shear_fail_webs_shear_buckling=FOS_webs_shear_buckling.*max_SFD;

figure;

% Subplot 1 - Shear Force Distribution (SFD)
subplot(1, 2, 1);
title('SFD');
hold on;

plot(bridge_distances, max_SFD, "-k", 'LineWidth', 2, 'DisplayName', 'Max SFD');
plot(bridge_distances, shear_fail_webs_shear, "--r", 'LineWidth', 2, 'DisplayName', 'Shear Fail Webs Shear');
plot(bridge_distances, shear_fail_top_glue_shear, "--y", 'LineWidth', 2, 'DisplayName', 'Shear Fail Top Glue Shear');
plot(bridge_distances, shear_fail_webs_shear_buckling, "--b", 'LineWidth', 2, 'DisplayName', 'Shear Fail Webs Shear Buckling');

for i=1:number_train_locations
%    plot(bridge_distances,SFD(i,:));
end

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
plot(bridge_distances, moment_fail_webs_flange_compressive_buckling, "--m", 'LineWidth', 2, 'DisplayName', 'Moment Fail Webs Flange Compressive Buckling');

for i=1:number_train_locations
%    plot(bridge_distances,BMD(i,:));
end

legend('show');
xlabel('Bridge Distances');
ylabel('Bending Moment');
grid on;

hold off;

% Switch Parameters to 400N, Load Case 1, Bridge Parameters for Design 0
% (Note: Don't forget to change diaphragm spacing)
disp("Hand Calculations Comparison");
disp("Max SFD: "+max(max_SFD));
disp("Max BMD: "+max(max_BMD));
disp("Min FOS for Tensile: " + min(FOS_tensile));
disp("Min FOS for Compressive: " + min(FOS_compressive));
disp("Min FOS between Compressive Buckling: " + min(FOS_between_compressive_buckling));
disp("Min FOS for Tips Compressive Buckling: " + min(FOS_tips_compressive_buckling));
disp("Min FOS for Webs Flange Compressive Buckling: " + min(FOS_webs_flange_compressive_buckling));
disp("Min FOS for Webs Shear: " + min(FOS_webs_shear));
disp("Min FOS for Top Glue Shear: " + min(FOS_top_glue_shear));
disp("Min FOS for Webs Shear Buckling: " + min(FOS_webs_shear_buckling));

min_value = min([FOS_tensile(:); FOS_compressive(:); FOS_between_compressive_buckling(:); FOS_tips_compressive_buckling(:); FOS_webs_flange_compressive_buckling(:); FOS_webs_shear(:); FOS_top_glue_shear(:); FOS_webs_shear_buckling(:)]);
% Getting Failure Load
disp("Failure Load: "+min(min_value)*train_total_weight);
