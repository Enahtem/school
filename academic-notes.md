TO GET RID OF. START TAKING NOTES ON PHYSICAL PAPER.

LINEAR ALGEBRA

- Vector Space (8 Vector Space Properties, Derived Properties)
- Subspaces (Subset, 3 Subspace Properties)
- Span: Set of All Linear Combinations of Vectors
- Linear Independence: $(\{v_1, v_2, ... v_n\} \text{ is linearly independent }) \iff (\Sigma_{j=1}^n \lambda_j v_j = 0 \implies \text { all } \lambda_j = 0)$
  - Span decreases for any vector removed
  - Add vector (not in the span) or removing vector retains independence
  - FToLA: $V=span\{v_1, v_2, ... v_n\}, \text{ m independent vectors: } \{w_1, w_2, ... w_m\} \in V \implies m\leq n$
- Linear Dependent: $(\{v_1, v_2, ... v_n\} \text{ is linearly dependent }) \iff (\Sigma_{j=1}^n \lambda_j v_j = 0 \centernot\implies \text { all } \lambda_j = 0)$
  - Span can be retained after removing a particular vector
  - Add vector retains dependence.
  - Has 0 vector or one vector is linear combinations of others
- Basis: Minimal Spanning Set
  - Dimension: Size of vector space's basis
  - Linearly independent set of n vectors, Spanning set of n vectors, Vector space dimension is n
- Matrix Spans
  - Row/Column Spans: $rowA, colA$. Rank: $rankA=dim (row A) = dim (col A)$
  - Image Space: $\{y|y=Ax\}$. Null Space: $\{x | Ax=0\}$. Rank-Nullity: $nullityA=\text{Number Columns} - rankA$
- Matrix Solutions
  - No Solution: $rankA < rank(A|B)$
  - 1 Solution: $rankA = rank(A|B) = n$
  - Infinite Solutions: $rankA = rank(A|B) < n$
- Matrix Invertibility
  - Square Matrix (nxn) Invertibility:
    - A has rank n, Lin Independent Columns/Rows, $Ax=0 \implies x=0$, $z^TA = 0 \implies z=0$
  - Non-square matrix (mxn) Invertibility
    - $rank A = n$, indepent columns, $Ax=0 \implies x=0$, $A^TA$ invertible, A has a left inverse
    - $rank A = m$, independent rows, $z^TA = 0 \implies z=0$, $AA^T$ invertible, A has a right inverse
- Linear Transformations: $L: V\rightarrow W$ (2 Linear Transformation Properties)
  - Image: Set of vectors in W that V can L(v) can transform to. Subsapce of W
  - Kernel: Set of vectors in v that L(v)=0. Subspace of V
  - Dimension theorem: $dim(kerL)+dim(imgL)=dim(V)$

ANALYSIS

- Limit Definition: $\lim_{x \to c} f(x) = L$ if for every $\epsilon>0$, there exists $\delta>0$ such that $0<|x-c|<\delta$ implies $|f(x) - L| < \epsilon$
  - Substitute $\delta$ into $|f(x) - L|$ using $0<|x-c|<\delta$, simplifying in direction of inequality towards $\epsilon$
  - Eliminate remaining x in $|f(x) - L|$, assuming $\delta=a$ if necessary
  - Equate $\delta$-dependent function to equal $\epsilon$. Choose $\delta=min(a, f(\epsilon))$ where $\delta>0$ for all $\epsilon>0$
  - Proof: Put $\delta=f(\epsilon)$ into $\delta$-dependent function and equate to $\epsilon$
- Limit Theorems: Constant/Sum/Difference/Constant Multiple/Product/Quotient
  - $\exists \lim_{x \to c} f(x)=L \iff \lim_{x \to c^+} f(x) = \lim_{x \to c^-} f(x) = L$
  - L'Hopital's Rule: If $f(x), g(x) \rightarrow 0, \pm \infty$ then $\frac{f(x)}{g(x)}=\frac{f'(x)}{g'(x)}=L$
    - For other forms of indeterminate limits, $\lim{f(x)}=e^{\lim(ln{f(x)})}$
- Derivative Definition: $f'(a)=\lim_{h \rightarrow0}\frac{f(a+h)-f(a)}{h}$
- Derivatives Theorems: Constant/Sum/Difference/Constant Multiple/Product/Power/Quotient/Chain/Trigonometric/Hyperbolic/Exponential/Logarithmic
  - Inverse Differentiation: $(f^{-1}(x))'=\frac{1}{f'(f^{-1}(x))}$
  - Parametric Differentiation: $\frac{dy}{dx}=\frac{y'(t)}{x'(t)}$
  - Polar Differentiation: $\frac{dy}{dx}=\frac{rcos\theta+sin\theta\frac{dr}{d\theta}}{-rsin\theta+cos\theta\frac{dr}{d\theta}}$
  - Implicit Differentiation: $y=f(x) \rightarrow F(x,y)=0 \rightarrow \frac{dF}{dx}+\frac{dF}{dy}y'=0$
  - Logarithmic Differentiation: $g(x)=g_1(x)g_2(x)$, $ln(g(x))=ln(g_1(x))+ln(g_2(x))$, $g'(x)=g(x)(\frac{g_1'(x)}{g_1(x)}+\frac{g_2'(x)}{g_2(x)})$
- Integral Definition: $\int_a^b f(x) dx=\lim_{n\to \infty}{\sum_{i=1}^{n}f(a+\frac{b-a}{n}i)\Delta x}$ (Right Riemann Sum). $\Delta x=\frac{b-a}{n}$ for uniform partition
  - Summations: $\Sigma_1^n i=\frac{(n)(n+1)}{2}$, $\Sigma_1^n i^2=\frac{(n)(n+1)(2n+1)}{6}$, $\Sigma_1^n i^3=(\frac{(n)(n+1)}{2})^2$
  - Improper Integrals: Infinite limits (Take limit), ranges across discontinuity (Take limit of either side of discontinuity)
- Integral Theorems: Opposite of Derivatives (Fundamental Theorem of Calculus)
- Integral Techniques
  - u-Substitution: $\int f(g(x))g'(x)dx=\int f(u)du$ for $u=g(x)$
  - Integration by Parts: $\int udv = uv - \int vdu$
  - Trigonometric Powers:
    - $\int \sin^mx\cos^nxdx$: Odd power, $u=\sin x, \cos x$. Even power, $\sin^2x=\frac{1}{2}(1-\cos2x), \cos^2x=\frac{1}{2}(1+\cos2x), \sin x \cos x = \frac{1}{2}\sin 2x$
    - $\int \tan^mx\sec^nxdx$: Odd $\tan x$ power, $u=\sec x$, even $\sec x$ power, $u=\tan x$
    - $\int \sin mx\cos nxdx$
      - $\sin A \cos B = \frac{1}{2} (\sin(A - B) + \sin(A + B))$
      - $\sin A \sin B = \frac{1}{2} (\cos(A + B) - \cos(A - B))$
      - $\cos A \cos B = \frac{1}{2} (\cos(A - B) + \cos(A + B))$
  - Trigonometric Substitution:
    - For $\sqrt{a^2-x^2}$, use $x=a\sin x$
    - For $\sqrt{a^2+x^2}$, use $x=a\tan x$
    - For $\sqrt{x^2-a^2}$, use $x=a\sec x$
  - Partial Fractions: Split rational functions into integrable parts
  - Rationalizing Substitution:
    - For $\sqrt[n]{g(x)}$, use $u = \sqrt[n]{g(x)}$
    - Weierstrass Substitution: $u=\tan{(\frac{x}{2})}$ turns trigonometric functions into rational functions.
      - $\sin{x} = \frac{2u}{1+u^2}$, $\cos{x} = \frac{1-u^2}{1+u^2}$, $\tan{x} = \frac{2u}{1-u^2}$
  - Parametric: $\int y(t) x'(t)dt$
  - Polar: $\frac{1}{2}\int \rho^2(\theta)d\theta$
- Differential Equations
  - Separable Differential Equations
  - First Order Linear: $y'+P(x)y=Q(x)$
    - $I(x)(y'+P(x)y)=I(x)Q(x)$ > $(I(x)y)'=I(x)Q(x)$ where $I(x)=e^{\int P(x)dx}$
  - Second Order Homogenous with Constant Coefficients: $ay''+by'+cy=0$
    - General Solution: $y=c_1y_1+c_2y_2$ (Linear Combination of Solutions)
    - Auxiliary Equation's ($ar^2+br+c$) Roots form solution
      - $y=c_1e^{r_2x}+c_2e^{r_2x}$ for 2 real solutions
      - $y=c_1e^{rx}+c_2xe^{rx}$ for 1 real solution
      - $y=e^{\alpha x}(c_1cos(\beta x)+c_2sin(\beta x))$
  - Second Order Non-Homogenous with Constant Coefficients: $ay''+by'+cy=G(x)$
    - General Solution: $y=y_p+y_c$
    - $y_c$ from homogenous solution
    - Method of Undetermined Coefficients
      - Guess $y_p$ as a variation of $G(x)$
      - If equivalent to $y_c$, multiply guess by x
    - Method of Variation of Parameters
      - $y_p=u_1y_1+u_2y_2$
      - Solve system of equations: $u_1'y_1+u_2'y_2=0$ and $a(u_1'y_1'+u_2'y_2')=G(x)$
- Theorems
  - Linear Approximation: $f(x+\Delta x) \approx f(x) + f'(x)\Delta x$
  - Squeeze Theorem: $\lim_{x \to c} f(x) = \lim_{x \to c} h(x) = L$. If $f(x)\leq g(x)\leq h(x)$, then $\lim_{x \to c} g(x) = L$
  - Intermediate Value Theorem: f(x) continuous on \[a,b\], there must be c within (a,b) for any number in (f(a), f(b))
  - Extreme Value Theorem: f(x) continuous on \[a,b\]. Must have an absolute max and min.
  - Rolle's Theorem: Continuous function on \[a,b\], differentiable on (a,b), f(a)=f(b), there is a point with slope 0
  - Mean Value Theorem: Continuous function on \[a,b\], differentiable on (a,b), there is a point with slope equal to secant
  - Cauchy Mean Value Theorem: Continuous functions on \[a,b\], differentiable on (a,b), there is a point with slope ratio equal to secant ratio
  - Mean Value Theorem for Integrals: Continuous function on \[a,b\] must have a point equal to average ($f(c) = \frac{\int_a^b f(x) dx}{b-a}$)
  - Fundamental Theorem of Calculus: $\frac{d}{dx}\int_a^{g(x)}f(t)dt = f(g(x))g'(x)$, $\int_a^b f'(x)dx=f(b)-f(a)$
  - Derivative of Inverse: For one-to-one function f(x), $(f^{-1})'(x)=\frac{1}{f'(f^{-1}(x))}$
    - One-to-one defined $f(x_1)=f(x_2)$ implies $x_1=x_2$. Or, always increasing/decreasing
- Curves
  - Curve Properties (Continuity/Differentiability/Integrability)
    - Continuity at a point if $\lim_{x \to c} f(x) = f(c)$
    - Continuity on \[a, b\]: Continuous on (a, b), at $x \to a^+$ and $x \to b^-$
    - Continuous across domain: Polynomial, Power (Root/Reciprocal), Rational (Polynomial Division), Algebraic (Polynomial Combination), Trigonometric, Exponential, Logarithmic, Continuous Functions Compositions
    - Differentiability at a point (f'(a) exists): ($\lim{f'(x)}_{x\rightarrow a}$ exists and f(x) is continuous at x=a)
    - Differentiability on \[a, b\]: Differentiable on (a, b), at $x \to a^+$ and $x \to b^-$
    - Differentiability of function: Derivative continuous across domain
    - Differentiability always implies continuity
    - Not differentiable at cusps, corners, discontinuities, and vertical tangents
    - Integrability implied by continuous domain (Continuity, Piecewise Continuity)
    - $\int_a^b f(x) dx\geq \int_a^b g(x) dx$ if $f(x)\geq g(x)$ on \[a,b\]
  - Curve Sketching (DRASID)
    - Quick Tests
      - QT1 Increasing/Decreasing Test: f'(x) exists on an interval. f'(x)>0 (Increasing), f'(x)<0 (Decreasing). f'(x)=0 (Constant)
      - QT2 1st Derivative Test: f'(x) exists on an interval, but not necessarily c. f(x) is fully continuous, even at c. f'(x) sign change about c: local min/max
      - QT3 Concavity/Point of Inflection: f''(x) exists on an interval. f''(x) > 0 (Concave up). f''(x)<0 (Concave down)
        - Point of Inflection: f''(x) changes signs and f(x) is continuous at c
      - QT4 2nd Derivative Test: f''(x) continuous about c. f'(c)=0. f''(x) > 0 (Local min). f''(x)<0 (Local max). f''(x) =0 (No Verdict)
    - General Behavior: Domain, Range, Asymptotes (vertical/horizontal/slant)
    - Symmetry (Even: f(-x)=f(x), Odd: f(-x)=-f(x), Periodic)
    - X, Y Intercepts
    - First Derivative
      - Find vertical tangent/cusp/corners (discontinuous derivative)
      - Intervals of QT1 (Increasing/Decreasing), Critical Points (f'(x)=0 or DNE)
        - Alternatively: Increasing/decreasing on interval $[a,b]$. Given $x_1<x_2$ prove $f(x_1)<f(x_2)$ or $f(x_1)>f(x_2)$
      - QT2 (First Derivative Sign Changes) to determine critical points as local max/min.
      - Find Absolute max/min (In closed interval)
        - Absolute Max/Min on Closed Interval \[a,b\]. Check f(c) where c=critical point, f(a), f(b)
    - Second Derivative
      - Intervals of QT3 (Concave Up/Concave Down), Inflection Points
      - QT4 (Second Derivative Sign) to confirm critical points as local max/min. f''(x) = 0 (No Verdict)
    - Function Transformations Check: $af(b(x-h))+k$. Shift right by h, up by k. Compress horizontally by b. Stretch vertically by a.
- Shapes
  - 3D Shapes
    - Ellipsoid: $x^2+y^2+z^2=1$
    - Cone: $z^2=x^2+y^2$
    - Elliptic Paraboloid: $z=x^2+y^2$
    - Hyperboloid of One Sheet: $x^2+y^2-z^2=1$
    - Hyperbolic Paraboloid: $z=x^2-y^2$
    - Hyperboloid of Two Sheets: $-x^2-y^2+z^2=1$
  - Centre of Mass
    - $\bar x=\frac{\int_a^b x(f(x)-g(x)) dx}{\int_a^b f(x)-g(x) dx}$
    - $\bar y=\frac{\int_a^b \frac{1}{2} x(f^2(x)-g^2(x)) dx}{\int_a^b f(x)-g(x) dx}$
  - Lengths
    - Arclength of Curve: $s=\int_{x_1}^{x_2} \sqrt{1+(\frac{dy}{dx})^2}dx$, $s=\int_{y_1}^{y_2} \sqrt{1+(\frac{dx}{dy})^2}dy$
    - Arclength of Parametric Curve: $s=\int_{t_1}^{t_2} \sqrt{(x'(t))^2+(y'(t))^2}dt$
    - Arclength of Polar Curve: $s=\int_{\theta_1}^{\theta_2} \sqrt{(r)^2+(\frac{dr}{d\theta})^2}d\theta$
  - Areas
    - Area between Curves: $A=\int f(x)-g(x) dx$
    - Surface Area of Rotated Curve: $A=\int 2\pi r ds$
  - Volumes
    - Volume by Slices: $V=\int A(x) dx$
    - Rotated Volume by Disks: $V=\int \pi [r(x)]^2 dx$
    - Rotated Volume by Washer: $V=\int \pi ([r_1(x)]^2-[r_2(x)]^2) dx$
    - Rotated Volume by Cylindrical Shells: $V=\int 2\pi r [h(r)] dr$
    - Rotated Volume by Theorem of Pappus: $V=2\pi \bar x A$
- Sum Convergence/Divergence - If $\lim_{i\rightarrow \infty}a_i\neq0$ then divergent. If $\lim_{i\rightarrow \infty}a_i=0$ then inconclusive. - Alternating series test (magnitude decreases to zero > convergent) - Check for similarities (comparison/division) to: - Comparison: Compare to an alternate sum with known divergence/convergence always $\geq/\leq$ it - Division: Divide by an alternate function (both positive functions). If term limit goes to positive number, same divergence/convergence) - p-series: $\Sigma_1^{\infty} \frac{1}{n^p}$. convergent $p>1$, divergent $p\leq 1$ - geometric series: $\Sigma_1^{\infty} ar^{n-1}=\frac{a(1-r^\infty)}{1-r}$. convergent $r<1$, divergent $r\geq 1$ - Ratio test (value ratio between terms approaches > convergent, divergent, inconclusive). Inconclusive for algebraic functions. - $lim_{i\rightarrow \infty} \frac{a_{n+1}}{a_n}=L$ - (Absolutely) Convergent: $|L|<1$, Divergent: $|L|>1$, Inconclusive: $L=1$ - Can also take nth root of L - Integral Test: (Continuous, Positive Function where $a_n=f(n)$) $\int_1^\infty f(x)dx$ is convergent/divergent then $\Sigma_1^\infty a_n$ is convergent/divergent - Finding Error - Remainder Theorem: $\int_{n+1}^\infty f(x)dx\leq s-s_n\leq \int_{n}^\infty f(x)dx$ - Alternating Remainder Theorem: $s-s_n=\Sigma_{n+1}^\infty (-1)^n a_n\leq a^{n+1}$ - Power Series: $f(x)=\sum_0^\infty c_n(x-a)^n$ - Converges only at $x=a$, $x\in R$, or $|x-a|<R$ - Generally use Ratio Test to find convergence - Function equivalent with $\frac{1}{1-x}=\sum_0^\infty x^n, |x|<1$ - Taylor Series: $f(x) = \sum_0^\infty \frac{f^{(n)}(a)}{n!}(x-a)^n$ - Only works within radius of convergence - Taylor Inequality: For $|x-a|\leq d: f^{(n+1)}(x)\leq M \implies |R_n(x)|\leq \frac{M}{(n+1)!}|x-a|^{n+1}$ - Show $lim_{n\rightarrow \infty}R_n(x)=0$ for valid Taylor series approximation. - Binomial Series: $(1+x)^k=\sum_0^\infty {k\choose n} x^n$ - Radius Convergence: 1 - Derivative/Integrals can be moved inside the sum. - Fourier Series: $f(x)=a_0+\Sigma_{1}^\infty(a_nsin(n\pi x/L)+b_ncos(n\pi x/L))$ - $a_0=\frac{1}{2L}\int_{-L}^L f(x)dx$ - $a_n=\frac{1}{L}\int_{-L}^L f(x)sin(n\pi x/L)dx$ - $b_n=\frac{1}{L}\int_{-L}^L f(x)cos(n\pi x/L)dx$
  STATISTICS
- ???

- Narrowed Code down to 2 Github Repositories (coincidentally both from emnlp 2022)
  - [IBM/Grapher: Code that implements efficient knowledge graph extraction from the textual descriptions (github.com)](https://github.com/IBM/Grapher/tree/main?tab=readme-ov-file)
    - Went more in depth into this one because it seemed simpler (Had like 6 python files total)
    - Step 1: Fixed number of node features extracted from text via T5 Tokenizer for entity extraction
      - (Causal masking disabled for permutation invariant nodes)
      - It says the node query input to the T5 model is learned. Does this just mean pre-trained?
      - Each node word selected from node features via greedy-decode LSTM/GRU
    - Step 2: Edges extracted from pairs of nodes features using LSTM/GRU or classification algorithms
      - If the output of an LSTM/GRU is a vector, how does that translate to a binary edge/no edge?
      - Would a classification algorithm have those two options as an output?
      - Direction of edge determined by value of feature vectors
    - One of the data sources, WebNLG, is open access
    - Concerns: Critiqued iterative/sequentially building knowledge graphs
      - Limited to local modifications and unable to build global graph structures
      - Has sequential and greedy nature leading to suboptimal graph structures.
      - Are these concerns valid? Does this imply that the process is incompatible with iterative models?
    - Tried to get it set up and i think it kind of worked but don't think there's enough processing power on my laptop
  - [zjunlp/DeepKE: [EMNLP 2022] An Open Toolkit for Knowledge Graph Extraction and Construction (github.com)](https://github.com/zjunlp/DeepKE?tab=readme-ov-file)
    - Has its own website with documentation and examples which seem very useful
      - THe online demos don't seem to work.
    - Has a few_shot low performace option that i tried to run but couldn't build properly.
    - I think there was a missing header file in the c compiler
  - Main takeaway:
    - Spent too long trying to install dependecies and other things
    - I'll try to understand the code and potentially recode it instead of trying to implement it
    - Is this recommended?
    - Could try to understand and implement individual parts of the two things?

PARSING INFORMATION
[Parsing Argumentation Structures in Persuasive Essays](https://aclanthology.org/J17-3005.pdf)

- Looked more at papers that cited Soricut/Marcu
  - Step 1: Recognizing Argument Features (Segmenting into Discourse Units)
    - Soricut mostly used as a small part in a larger model of parsing argumentations ("Identifying Argument Components: Structural Features, Syntactic Features, Lexico-Syntactic Features (SORICUT/MARKU), Probability Features").
  - Step 2: Recognizing Argument Structure
    - Classifying Argument Components (Many Features + SVM): MajorClaim,Claim, Premise
    - Identifying Argumentative Relations. (Many Features + SVM): incoming, outgoing
      - Can use similar features, but change categories to fiction related things (Entities/Relationships)
    - Optimizing Components and Relations ('Integer Linear Programming': Iterating over all possibilites. FInding maximum)
      - Organizing into most likely Structured Graph
  - Step 3: Classifying as Supportp and Attack(Features/SVM)

KNOWLEDGE GRAPHS (TAXONOMIES/ENTITIES/RELATIONS) OF FICTIONAL TEXTS
[Knowledge Extraction from Fictional Texts](https://publikationen.sulb.uni-saarland.de/bitstream/20.500.11880/32914/1/thesis-twoside-toprint.pdf)

- Can reference features to gather and categories to fit of entities and relations.
  - Entity Typing
    - Supervised Typing:
      - General Categories FROM WORDNET?? (living thing, location, organization, object, time, event, substance)
        - Referenced wordnet. What exactly is wordnet and what do they use the categoreies for? Are there more than just these 7? What abotu the EXCEPTIONS?
      - Certain number of (Measure of accuracy.) top performing types (TD-IDF?)
    - Supervised REal World Types: (Data mining wikipedia)
    - Unsupervised Typing: "36 Pattern Based Methods"
      - WHAT IS THIS? "pattern-based and dependency-based method to extract types directly from the input text"
  - Relation Identification
    - "Distantly supervised neural learning has become the method of choice (for relation extraction), with different granularities"
- Also uses Integer Linear Programming.
  - IS THIS AN OPTIMIZATION ALGORITHM?

Statistical Measures: Precision vs Recall

INCREMENTING ON KNOWLEDGE GRAPHS. (STRUCTURE)
[A Scalable Approach to Incrementally Building Knowledge Graphs](https://usc-isi-i2.github.io/papers/gleb16-tpdl.pdf)

- Filter > Schema Mapping > If Input Graph Provided: (Candidate Generation > Linking) > Consolidation
- Filter: Identifying Target entities
- Schema Mapping: Parsing/Formatting text into entities/relations
  - Uses schema.org - Semantic Web Database???
- Candidate Generation: Finding potential linking knowledge. MinHash/LSH algorithm
- Linking: Finalizing selected linked knowledge
- Consolidation: Actually linking the things

- Evaluating Nodes: Checking knowledge in realtion to ground truth data
- Evaluating Edges: Checking similarity relations of connected nodes.

Sentence Level Discourse Parsing using Syntactic and Lexical Information (Soricut/Marku)

- [synrstWithAuthors.dvi (aclanthology.org)](https://aclanthology.org/N03-1030.pdf)
- Sentence-Level Dependency Parsing
- Discourse Structure: Epistemological Networks (Tree Form)
  - Nodes: Nucleus (Central)/Satellite (Supporting)
  - Edges: Attribution (Who?)/Enablement (Why?)
- Corpus RST-DT, 2002 UNAVAILABLE? HOW TO GET? [RST Discourse Treebank - Linguistic Data Consortium (upenn.edu)](https://catalog.ldc.upenn.edu/LDC2002T07)
  - Human Annotated
  - Sentence, Syntactic Tree (Parts of Speech), Sentence-Level Discourse Tree
- Main Purpose: Sentence (Lexical Syntactically Annotated) > Generated Sentence Discourse Tree (Checked with Annotated Sentences)
- Step 1: Discourse Segmentation into Discourse Units (Edus/Nodes)
  - Statistical model which inserts discourse boundary probabilities
    - Probability based on children in syntactic tree
    - Calculated by rule frequency in corpus
  - Segmenter that splits using these probabilities (If Probability > 0.5)
- Step 2: Discourse Segmented Lexicalized Syntactic Tree to Discourse Tree
  - Creates discourse trees
    - Sets of tuples that tell you relationship between discourse spans (binary)
    - Dominance Set. Take Head of Edus and find what other edu contains the connection to the head.
  - Analysis probability
    - Measure of 'goodness' of each tuple and relationship and dominance set for every possible tree.
    - IS THE PROBABILITY ALSO CALCULATED BY FREQUENCY IN THE CORPUS?

UTAT Destriping

- Upload GitHub Add Stripes/Pipeline Stuff
- Add [Apply Stripes Tests - Google Docs](https://docs.google.com/document/d/1ES0StxI823yJJY8EvKE4ErY6bHjcFT87qHLuHIzn-mI/edit#heading=h.ihl4l6s7ruwx) to Notion
- DDPM Stuff
  - [w86763777/pytorch-ddpm: Unofficial PyTorch implementation of Denoising Diffusion Probabilistic Models (github.com)](https://github.com/w86763777/pytorch-ddpm)
  - [lucidrains/denoising-diffusion-pytorch: Implementation of Denoising Diffusion Probabilistic Model in Pytorch (github.com)](https://github.com/lucidrains/denoising-diffusion-pytorch)
  - [hojonathanho/diffusion: Denoising Diffusion Probabilistic Models (github.com)](https://github.com/hojonathanho/diffusion)

[Foobar](https://foobar.withgoogle.com/#) - enahtem.ch4@gmail.com (Python)
