#include <iostream>
#include <string>
#include <sstream>


namespace kimc::lib {
	std::string find_sequence_of_keypresses(std::string inputStr)
	{
		std::string outputStr = " ";

		for (char letter : inputStr)
		{
			std::string curStr = "";
			switch (letter)
			{
			case 'a':
			{
				if (outputStr.back() == '2')
				{
					curStr += " ";
				}
				curStr += "2";
				break;
			}
			case 'b':
			{
				if (outputStr.back() == '2')
				{
					curStr += " ";
				}
				curStr += "22";
				break;
			}
			case 'c':
			{
				if (outputStr.back() == '2')
				{
					curStr += " ";
				}
				curStr += "222";
				break;
			}
			case 'd':
			{
				if (outputStr.back() == '3')
				{
					curStr += " ";
				}
				curStr += "3";
				break;
			}
			case 'e':
			{
				if (outputStr.back() == '3')
				{
					curStr += " ";
				}
				curStr += "33";
				break;
			}
			case 'f':
			{
				if (outputStr.back() == '3')
				{
					curStr += " ";
				}
				curStr += "333";
				break;
			}
			case 'g':
			{
				if (outputStr.back() == '4')
				{
					curStr += " ";
				}
				curStr += "4";
				break;
			}
			case 'h':
			{
				if (outputStr.back() == '4')
				{
					curStr += " ";
				}
				curStr += "44";
				break;
			}
			case 'i':
			{
				if (outputStr.back() == '4')
				{
					curStr += " ";
				}
				curStr += "444";
				break;
			}
			case 'j':
			{
				if (outputStr.back() == '5')
				{
					curStr += " ";
				}
				curStr += "5";
				break;
			}
			case 'k':
			{
				if (outputStr.back() == '5')
				{
					curStr += " ";
				}
				curStr += "55";
				break;
			}
			case 'l':
			{
				if (outputStr.back() == '5')
				{
					curStr += " ";
				}
				curStr += "555";
				break;
			}
			case 'm':
			{
				if (outputStr.back() == '6')
				{
					curStr += " ";
				}
				curStr += "6";
				break;
			}
			case 'n':
			{
				if (outputStr.back() == '6')
				{
					curStr += " ";
				}
				curStr += "66";
				break;
			}
			case 'o':
			{
				if (outputStr.back() == '6')
				{
					curStr += " ";
				}
				curStr += "666";
				break;
			}
			case 'p':
			{
				if (outputStr.back() == '7')
				{
					curStr += " ";
				}
				curStr += "7";
				break;
			}
			case 'q':
			{
				if (outputStr.back() == '7')
				{
					curStr += " ";
				}
				curStr += "77";
				break;
			}
			case 'r':
			{
				if (outputStr.back() == '7')
				{
					curStr += " ";
				}
				curStr += "777";
				break;
			}
			case 's':
			{
				if (outputStr.back() == '7')
				{
					curStr += " ";
				}
				curStr += "7777";
				break;
			}
			case 't':
			{
				if (outputStr.back() == '8')
				{
					curStr += " ";
				}
				curStr += "8";
				break;
			}
			case 'u':
			{
				if (outputStr.back() == '8')
				{
					curStr += " ";
				}
				curStr += "88";
				break;
			}
			case 'v':
			{
				if (outputStr.back() == '8')
				{
					curStr += " ";
				}
				curStr += "888";
				break;
			}
			case 'w':
			{
				if (outputStr.back() == '9')
				{
					curStr += " ";
				}
				curStr += "9";
				break;
			}
			case 'x':
			{
				if (outputStr.back() == '9')
				{
					curStr += " ";
				}
				curStr += "99";
				break;
			}
			case 'y':
			{
				if (outputStr.back() == '9')
				{
					curStr += " ";
				}
				curStr += "999";
				break;
			}
			case 'z':
			{
				if (outputStr.back() == '9')
				{
					curStr += " ";
				}
				curStr += "9999";
				break;
			}
			case ' ':
			{
				if (outputStr.back() == '0')
				{
					curStr += " ";
				}
				curStr += "0";
				break;
			}
			default:
			{
				std::cout << "error";
				break;
			}
			
			}
			outputStr += curStr;
		}
		return outputStr;
	}
}


int main()
{
	// 입력 최적화
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	std::string inputStr;
	std::getline(std::cin, inputStr); 
	std::stringstream ss(inputStr);

	int32_t caseCount;
	ss >> caseCount;
	ss.clear();
	ss.seekg(0);

	for (int32_t i = 0; i < caseCount; i++)
	{
		std::getline(std::cin, inputStr);
		ss.str(inputStr);
		ss.clear();
		ss.seekg(0);

		std::string outputStr = "";
		outputStr += "Case #" + std::to_string(i+1) + ":";
		outputStr += kimc::lib::find_sequence_of_keypresses(inputStr);
		outputStr += "\n";
		std::cout << outputStr;
	}
}