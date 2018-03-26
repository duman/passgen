#include <duman.h>
using namespace std;

int main(const int argc, char* argv[])
{
	cerr << "###\n";
	if(argc > 1 && argc <= 2)
	{
		if(string(argv[1]) == "-h")
		{
			cerr << "Usage              : " << get_file_name(argv[0]) << " -<length> -<min security out of 100> -<with/out_symbols>\n";
			cerr << "Example w/  symbols: " << get_file_name(argv[0]) << " -12 -80 -s\n";
			cerr << "Example w/o symbols: " << get_file_name(argv[0]) << " -12 -80 -ns\n\n";
			cerr << "Password will be automatically copied to your clipboard!\n";
			cerr << "###\n";
			return 1;
		}
		if(string(argv[1]) == "-v")
		{
			cerr << "Author : Tugberk Kaan Duman\n";
			cerr << "Contact: kaan@dumanmail.com\n";
			cerr << "Version: 1.4.2\n";
			cerr << "###\n";
			return 2;
		}
		if(string(argv[1]) == "-length" || string(argv[1]) == "-l")
		{
			cerr << "Try to use the command as:\n";
			cerr << get_file_name(argv[0]) << " -8 -98 -ns # for a password that has length of 8 and security score of minimum 98 that doesn\'t include symbols.\n";
			cerr << get_file_name(argv[0]) << " -8 -98 -s  # for a password that has length of 8 and security score of minimum 98 that doesn include symbols.\n";
			cerr << "###\n";
			return 2;
		}
	}
	if(argc > 2 && argc <= 3)
	{
		string raw_argument1 = argv[1];
		string raw_argument2 = argv[2];

		for(unsigned int i = 1; i < raw_argument1.length(); i++)
		{
			if(!isdigit(raw_argument1[i]))
			{
				cerr << "Invalid parameters! Use -h to see how to use this program.\n";
				cerr << "###\n";
				return 1;
			}
		}
		for(unsigned int i = 1; i < raw_argument2.length(); i++)
		{
			if(!isdigit(raw_argument2[i]))
			{
				cerr << "Invalid parameters! Use -h to see how to use this program.\n";
				cerr << "###\n";
				return 1;
			}
		}
		if(raw_argument1[0] != '-')
		{
			cerr << "Did you mean: " << get_file_name(argv[0]) << " -" << argv[1] << " " << raw_argument2 << " # missing dash before an argument!\n";
			cerr << "###\n";
			return 1;
		}
		if(raw_argument2[0] != '-')
		{
			cerr << "Did you mean: " << get_file_name(argv[0]) << " " << raw_argument1 << " -" << argv[2] << " # missing dash before an argument!\n";
			cerr << "###\n";
			return 1;
		}
		if(string(argv[1]).empty() || string(argv[2]).empty())
		{
			cerr << "Missing parameters! Use -h to see how to use this program!\n";
			cerr << "###\n";
			return 1;
		}
		raw_argument1.erase(raw_argument1.begin());
		raw_argument2.erase(raw_argument2.begin());
		const auto first_argument = stoi(raw_argument1);
		const auto second_argument = stoi(raw_argument2);
		auto seconds_since_start = 0;

		const auto symbols = false;

		const auto start = time(nullptr);
		
		auto generated_password = password_generator(first_argument, symbols, true);
		
		while(password_score(generated_password) < second_argument)
		{
			if(password_score(generated_password) >= second_argument)
			{
				break;
			}
			generated_password = password_generator(first_argument, symbols, true);
			seconds_since_start += static_cast<int>(difftime(time(nullptr), start));
			if(seconds_since_start > 50)
			{
				cerr << "Request timed out. Couldn't generate a password with the given parameters.\n";
				cerr << "###\n";
				return 1;
			}
		}
		cerr << "Generated password strength: " << password_score(generated_password) << "/100\n";
		cerr << "Password symbol status     : " << boolalpha << symbols << "\n";
		cerr << "Password has been copied to clipboard!\n";
		cerr << "###\n";
		return 0;
	}
	if(argc > 3 && argc <= 4)
	{
		string raw_argument1 = argv[1];
		string raw_argument2 = argv[2];
		string raw_argument3 = argv[3];
		for(unsigned int i = 1; i < raw_argument1.length(); i++)
		{
			if(!isdigit(raw_argument1[i]))
			{
				cerr << "Invalid parameters! Use -h to see how to use this program.\n";
				cerr << "###\n";
				return 1;
			}
		}
		for(unsigned int i = 1; i < raw_argument2.length(); i++)
		{
			if(!isdigit(raw_argument2[i]))
			{
				cerr << "Invalid parameters! Use -h to see how to use this program.\n";
				cerr << "###\n";
				return 1;
			}
		}
		for(unsigned int i = 1; i < raw_argument3.length(); i++)
		{
			if(isdigit(raw_argument3[i]))
			{
				cerr << "Invalid parameters! Use -h to see how to use this program.\n";
				cerr << "###\n";
				return 1;
			}
		}
		if(raw_argument1[0] != '-')
		{
			cerr << "Did you mean: " << get_file_name(argv[0]) << " -" << argv[1] << " " << raw_argument2 << " " << raw_argument3 << " # missing dash before an argument!\n";
			cerr << "###\n";
			return 1;
		}
		if(raw_argument2[0] != '-')
		{
			cerr << "Did you mean: " << get_file_name(argv[0]) << " " << raw_argument1 << " -" << argv[2] << " " << raw_argument3 << " # missing dash before an argument!\n";
			cerr << "###\n";
			return 1;
		}
		if(raw_argument3[0] != '-')
		{
			cerr << "Did you mean: " << get_file_name(argv[0]) << " " << raw_argument1 << " " << raw_argument2 << " -" << argv[3] << " # missing dash before an argument!\n";
			cerr << "###\n";
			return 1;
		}
		if(string(argv[1]).empty() || string(argv[2]).empty() || string(argv[3]).length() == 0 || string(argv[3]).empty())
		{
			cerr << "Missing parameters! Use -h to see how to use this program!\n";
			cerr << "###\n";
			return 1;
		}
		raw_argument1.erase(raw_argument1.begin());
		raw_argument2.erase(raw_argument2.begin());
		const auto first_argument = stoi(raw_argument1);
		const auto second_argument = stoi(raw_argument2);
		auto seconds_since_start = 0;

		auto symbols = false;

		if(string(argv[3]) == "-nosym" || string(argv[3]) == "-ns")
		{
			symbols = false;
		}

		if(string(argv[3]) == "-sym" || string(argv[3]) == "-s")
		{
			symbols = true;
		}

		const auto start = time(nullptr);
		
		auto generated_password = password_generator(first_argument, symbols, true);
		
		while(password_score(generated_password) < second_argument)
		{
			if(password_score(generated_password) >= second_argument)
			{
				break;
			}
			generated_password = password_generator(first_argument, symbols, true);
			seconds_since_start += static_cast<int>(difftime(time(nullptr), start));
			if(seconds_since_start > 50)
			{
				cerr << "Request timed out. Couldn't generate a password with the given parameters.\n";
				cerr << "###\n";
				return 1;
			}
		}
		cerr << "Generated password strength: " << password_score(generated_password) << "/100\n";
		cerr << "Password symbol status     : " << boolalpha << symbols << "\n";
		cerr << "Password has been copied to clipboard!\n";
		cerr << "###\n";
		return 0;
	}
	if(argc > 4)
	{
		cerr << "Unsupported number of parameters!\n";
		return 1;
	}
	cerr << "Commands:\n";
	cerr << "1. " << get_file_name(argv[0]) << " -length -security_level -symbol_status # Security level is XYZ out of 100\n";
	cerr << "2. " << get_file_name(argv[0]) << " -h\n";
	cerr << "3. " << get_file_name(argv[0]) << " -l\n";
	cerr << "4. " << get_file_name(argv[0]) << " -v\n";
	cerr << "###\n";
}
