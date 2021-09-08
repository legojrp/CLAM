#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
class CLAM {
public:
	CLAM(std::string path, int CLAMfileversion = 1, std::string customKey = "$C**M$"){
    	this->path = path;
      	if (CLAMfileversion == 1){
        	
      }

    }
	inline void writeToProperty(std::string Property, std::string Replacement);
	inline std::string readFromProperty(std::string Property);
	inline void createSubset();
	inline void createProperty(std::string Property, std::string Replacement);
private:
	std::string path;
	int CLAMfileversion;
	std::string customKey;
	//.clam
	inline void clam_writeToProperty(std::string Property, std::string Replacement);
	inline std::string clam_readFromProperty(std::string Property);
	inline void clam_createProperty(std::string Property, std::string Replacement);
	//.clam2
	inline std::string clam2_getCustomKey();
	inline void clam2_writeToProperty(std::string Property, std::string Replacement);
	inline std::string clam2_readFromProperty(std::string Property);
	inline void clam2_createProperty(std::string Property, std::string Replacement);
	inline int clam2_changeCustomKey(std::string key);
	inline int createPassword(std::string password);

};
//ALL
/*
*
*
*
*
*
*
*
*/
std::string CLAM::readFromProperty(std::string Property){
//for later C++ 2.0-beta.2.0
}
void CLAM::writeToProperty(std::string Property, std::string Replacement){
}
void CLAM::createProperty(std::string Property, std::string Replacement){
  	std::ofstream file(this->path);
    file << Property + ": " + Replacement + "\n";
    file.close();
}







//CLAM
/*
*
*
*
*
*
*/
	std::string CLAM::clam_readFromProperty(std::string Property){
 		std::ifstream file(this->path);
  		std::string text;
  		std::string returnstring = "";
   			while (std::getline(file, text)){
				if (text.substr(0, text.find(": "))== Property){
					returnstring = text.erase(0, Property.length() + 1);
    			}
			}
  		if (returnstring == ""){
  				returnstring = "Error";
  			}
  		return returnstring;

	}


	void CLAM::clam_writeToProperty(std::string Property, std::string Replacement){
		std::ifstream file(this->path);
  		std::string text, pre, post, changed;
    	int preOrPost = 0;
    	while (std::getline(file, text)){
      		if (text.substr(0, text.find(": ")) == Property){
         		preOrPost= 1;
        		continue;
      		}
      		else if ( preOrPost == 0){
        		pre += text + "\n";
      		}
      		else if (preOrPost == 1){
        		post += text + "\n";
      		}

    	}
    	changed = pre + Property + ": " + Replacement + "\n" + post;
    	file.close();
    	std::remove(this->path.c_str());
    	std::ofstream file2(this->path);
    	file2 << changed;
    	file2.close();
}
	void CLAM::clam_createProperty(std::string Property, std::string Replacement){
  		std::ofstream file(this->path);
    	file << Property + ": " + Replacement + "\n";
    	file.close();
}
//CLAM2
/*
*
*
*
*
*
*
*/
    std::string CLAM::clam2_getCustomKey(){
		std::ifstream file(this->path);
     	if (this->CLAMfileversion != 2){
          return "ERROR";
        }
  		std::string text;
  		std::string returnstring = "";
   		while (std::getline(file, text)){
			if (text.substr(0, text.find(": "))== Property){
				returnstring = text.erase(0, Property.length() + 1);
              if (Property == "CustomKey"){
					this->customKey = returnstring;
              }
              else {
					continue;
              }
              
    		}
          else {
            if (text.find("///")){
              return "Error";
            }
          }
		}
  		if (returnstring == ""){
  			returnstring = "Error";
  		}
  		return returnstring;

	}
    
    void CLAM::clam2_writeToProperty(std::string Property, std::string Replacement){
		std::ifstream file(this->path);
  		std::string text, pre, post, changed;
    	int preOrPost = 0;
    	while (std::getline(file, text)){
          	if (settingsOrAfter == 1){
            }
          	else if (text.afind("///")) {
				settingsOr
            }
      		if (text.substr(0, text.find(this->customKey) == Property){
         		preOrPost= 1;
        		continue;
      		}
      		else if ( preOrPost == 0){
        		pre += text + "\n";
      		}
      		else if (preOrPost == 1){
        		post += text + "\n";
      		}

    	}
    	changed = pre + Property + this->customKey + Replacement + "\n" + post;
    	file.close();
    	std::remove(this->path.c_str());
    	std::ofstream file2(this->path);
    	file2 << changed;
    	file2.close();
    }

	std::string CLAM::clam2_readFromProperty(std::string Property){
 		std::ifstream file(this->path);
  		std::string text;
  		std::string returnstring = "";
   		while (std::getline(file, text)){
			if (text.substr(0, text.find(this->customKey))== Property){
				returnstring = text.erase(0, Property.length() + 1);
    		}


   		}
  		if (returnstring == ""){
  			returnstring = "Error";
  		}
  		return returnstring;

	}
	
	void CLAM::clam2_createProperty(std::string Property, std::string Replacement){
		std::ofstream file(this->path);
    	file << Property + this->customKey + Replacement + "\n";
    	file.close();
	}
	int CLAM::clam2_changeCustomKey(std::string key){
		
	}

