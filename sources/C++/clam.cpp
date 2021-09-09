#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
//grading system for each method is as follows
//(overall grade).(debugged, 0 or 1).(speed / optimization grade).(Actual speed).(Organization Grade).(Error Protection).(documentation/explaination).(time of grading) >> (Any comments)
class CLAM {
public:
	CLAM(std::string path, int CLAMfileversion = 1, std::string customKey = "$C**M$"){// ---
    	this->path = path;
      	if (CLAMfileversion == 1){

      }

    }
	inline void writeToProperty(std::string Property, std::string Replacement); // ---
	inline std::string readFromProperty(std::string Property);// ---
	inline void createSubset();// ---
	inline void createProperty(std::string Property, std::string Replacement);//---
private:
	std::string path;//
	int CLAMfileversion;//
	std::string customKey;//
	//.clam
	inline void clam_writeToProperty(std::string Property, std::string Replacement);// 2.0.3.__.4.2.0.(8.9.21) >> good -- could be optimized, with the deleting of the file and reopening. Speed test coming sooon
	inline std::string clam_readFromProperty(std::string Property);// 5.0.8.__.9.2.0.(8.9.21)
	inline void clam_createProperty(std::string Property, std::string Replacement);//5.0.9.__.9.1.0(8.9.21)
	//.clam2
	inline std::string clam2_getCustomKey();//
	inline void clam2_writeToProperty(std::string Property, std::string Replacement);//
	inline std::string clam2_readFromProperty(std::string Property);//
	inline void clam2_createProperty(std::string Property, std::string Replacement);//
	inline int clam2_changeCustomKey(std::string key);//
	inline int createPassword(std::string password);//

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
      			if (text.substr(0, text.find(this->customKey)) == Property){
         			preOrPost= 1;
        			continue;
      			}
      			else if (preOrPost == 0){
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
	void CLAM::clam_createProperty(std::string Property, std::string Replacement){
  		std::ofstream file(this->path);
    		file << Property + this->customKey + Replacement + "\n";
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
	std::string CLAM::clam2_getCustomKey(){ /// +3 error, -2 error, + 4 organization,
		std::ifstream file(this->path);
     		if (this->CLAMfileversion != 2){
        		return "ERROR";
       		}
		std::string Property = "customKey";
  		std::string text;
  		std::string returnstring = "";
   		while (std::getline(file, text)){
			if (text.substr(0, text.find(": ")) == Property){
				returnstring = text.erase(0, Property.length() + 1);
				this->customKey = returnstring;
            }
            else {
                if (text.find("///")){
                    return "$C**M$ e: 1.2.1";
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
        int settingsOrAfter = 0;
    	int preOrPost = 0;
    	while (std::getline(file, text)){
          	if (settingsOrAfter == 0){
                    continue;
            }
          	else if (text.find("///")) {
				settingsOrAfter = 1;
            }
            else if (settingsOrAfter == 1){
                if (text.substr(0, text.find(this->customKey)) == Property){
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

