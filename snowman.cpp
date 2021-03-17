#include "snowman.hpp"
#include <vector>

using namespace std;

namespace ariel{

	const int hat = 0;
	const int nose = 1;
	const int l_eye = 2;
	const int r_eye = 3;
	const int l_arm = 4;
	const int r_arm = 5;
	const int torso = 6;
	const int base = 7;
	
	const int one = 1;
	const int four = 4;
	const int seven = 7;
	const int eight = 8;
	const int ten = 10;

	const std::vector<std::string> hats = {"\n _===_"," ___ \n .....  ","  _  \n  /_\\"," ___\n (_*_)"};
	const std::vector<std::string> noses = {",",".","_"," "};
	const std::vector<std::string> eyes = {".","o","O","-"};
	const std::vector<std::string> left_arm_up = {" ","\\"," "," "};
	const std::vector<std::string> left_arm_down = {"<"," ","/"," "};
	const std::vector<std::string> right_arm_up = {" ","/"," "," "};
	const std::vector<std::string> right_arm_down = {">"," ","\\"," "};
	const std::vector<std::string> torsos = {" : ","] [","> <","   "};
	const std::vector<std::string> bases = {" : ","\" \"","___","   "};

	string snowman(int snow){
		string str_num = to_string(snow);
		string snow_man = " ";
		if(str_num.length() == eight)
		{
			vector<int> inst = {0,0,0,0,0,0,0,0};
			for(int i = 0; i < str_num.length(); i++)
			{
				if((snow%ten < one) || (snow%ten > four))
				{
					throw std::out_of_range("input error");
					}
				
				inst.at(seven-i) = snow%ten;
				snow /= ten;					
			}

			snow_man += hats[inst[hat] - 1] + "\n";
			snow_man += left_arm_up[inst[l_arm] - 1] + "(";
			snow_man += eyes[inst[l_eye] - 1] + noses[inst[nose] - 1] + eyes[inst[r_eye] - 1];
			snow_man += ")" + right_arm_up[inst[r_arm] - 1] + "\n";	
			snow_man += left_arm_down[inst[l_arm] - 1] + "(";
			snow_man += torsos[inst[torso] - 1];
			snow_man += ")" + right_arm_down[inst[r_arm] - 1] + "\n";
			snow_man += " (" + bases[inst[base] - 1] + ")\n";
			
		}
		else{
			throw std::out_of_range("input out of range");
		}

		return snow_man;
	}
}
