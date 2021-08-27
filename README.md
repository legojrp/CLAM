# CLAM
Cross Language dAta Manipulation  
CLAM is MLP certified [shown here](https://github.com/legojrp/The-Multi-Language-Project) .  
CLAM is a multi-platform library. Currently only in C++. it is going to expand in 5 languages.
Formerly UserDataHandlerCpp
# How to use
# Support
### Level classification
Support is classified in 5 levels, and all features in lower levels are included in higher ones, unless otherwise stated. Ex. 2 through 5 include features from level 1.
* Level 0: Planned for future use.
* Level 1: minimal features (Input, Output, and little updating and fixing.) (.clam support)
* Level 2: Addition of support of little fixes
* Level 3: .clam2 support, continual updating
* Level 4: .clam to .clam2 conversion support
* Level 5: Main language support. (All others languages' methods are based of th(ese, is)language(s).

### Language Classification
Will go in format of "language : current level : planned level : version"
* C++ : 2 : 5 : 1.2
* Python : 0 : 4 : 0.1
* C# : 0 : 2 : 0.1
* JS : 0 : 0.5 (In local storage) : 0.1
* Java : 0 : 2 : 0.1
* C : 0 : 2 : 0.1
* PHP : 0 : 1 : 0.1
* GO : 0  : 1 : 0.1
# .clam (LTS)
.clam is the file extension used for CLAM. it is currently having long term support (LTS), and is in text encoding, meaning it is similar to a .txt or other text file is. 
# .clam2 (LTS) (Future)
.clam2 is the next-generation of file, with easier and better syntax. Specifics coming soon. Subosets are a main feature.
# Future
### All 
* Bug fixing
### Level 3 or higher
* .clam2
### Level 4 or higher
* .clam to .clam2 conversion.
### Level 5
* Function additions
# Documentation
## .clam
.clam is the 1st-generation and most supported file type of CLAM. It has a syntax like this:  
` property :  value `  
.clam has no subset support. 
##.clam2
.clam2 is the 2nd-generation file type of CLAM. It is currently being developed, and is syntax like this:  
`property "custom_key" value`  
.clam2 has a key system for seperation, and is editable based on the top line on a file. If none is present, or there is none specified on creation, or editing, then it defaults to `$C**M$`.  
Top of the file:
`###CODE_KEY="code key"`
