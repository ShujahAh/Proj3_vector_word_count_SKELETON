

#include "../includes/array_functions.h"
#include "../includes/utilities.h"


namespace KP{
	//zero out vector that tracks words and their occurrences
	void clear(std::vector<constants::entry>  &entries){
		entries.clear();
	}

		//how many unique words are in the vector
	int getSize(std::vector<constants::entry>  &entries){
		return entries.size();
	}

		//get data at a particular location, if i>size() then get the last value in the vector
		//(this is lazy, should throw an exception instead)
	std::string getWordAt(std::vector<constants::entry>  &entries, int i){
		return entries.at(i).word;
	}

	int getNumbOccurAt(std::vector<constants::entry>  &entries,int i){
		return entries.at(i).number_occurences;
	}

		/*loop through whole file, one line at a time
		 * call processLine on each line from the file
		 * returns false: myfstream is not open
		 *         true: otherwise*/
	bool processFile(std::vector<constants::entry>  &entries,std::fstream &myfstream){
		if (!myfstream.is_open()){
			return false;
		}
		return true;
	}


		/*take 1 line and extract all the tokens from it
		feed each token to processToken for recording*/
	void processLine(std::vector<constants::entry>  &entries,std::string &myString){

	}

		/*Keep track of how many times each token seen*/
	void processToken(std::vector<constants::entry>  &entries,std::string &token){
		std::string p = token;
		toUpper(p);
		for (constants::entry i: entries){
			if (i.word_uppercase.compare(p)==0){
				i.number_occurences += 1;
				return;
			}
		}
		constants::entry n;
		n.number_occurences= 0;
		n.word = token;
		n.word_uppercase = p;
		entries.push_back(n);
	}

		/*
		 * Sort myEntryArray based on so enum value.
		 * Please provide a solution that sorts according to the enum
		 * The presence of the enum implies a switch statement based on its value
		 * See the course lectures and demo project for how to sort a vector of structs
		 */
	void sort(std::vector<constants::entry>  &entries, constants::sortOrder so){
		int size = entries.size();
		switch(so){
			case(constants::sortOrder::NUMBER_OCCURRENCES):
				for (int i = 0;i <size; i++){
					for (int j = 1;j <size; j++){
							if (entries.at(i).number_occurences < entries.at(j).number_occurences){
								constants::entry tmp = entries.at(i);
								entries.at(i) = entries.at(j);
								entries.at(j)= tmp;
							}
					}
				}
				break;
			case(constants::sortOrder::DESCENDING):
				for (int i = 0;i <size; i++){
					for (int j = 1;j <size; j++){
						if (entries.at(i).word_uppercase < entries.at(j).word_uppercase){
								constants::entry tmp = entries.at(i);
								entries.at(i) = entries.at(j);
								entries.at(j)= tmp;
						}
					}
				}
				break;
			case(constants::sortOrder::ASCENDING):
				for (int i = 0;i <size; i++){
					for (int j = 1;j <size; j++){
							if (entries.at(i).number_occurences > entries.at(j).number_occurences){
								constants::entry tmp = entries.at(i);
								entries.at(i) = entries.at(j);
								entries.at(j)= tmp;
							}
					}
				}
				break;
			case(constants::sortOrder::NONE):
					break;
		}
	}
}
