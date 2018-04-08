#include <duman.h>
using namespace std;

int main(const int argc, char* argv[])
{
	cout << "###\n";
	if(argc > 1 && argc <= 2)
	{
		if(string(argv[1]) == "-h")
		{
			cout << "Usage              : " << get_file_name(argv[0]) << " -<length> -<min security out of 100> -<with/out_symbols>\n";
			cout << "Example w/  symbols: " << get_file_name(argv[0]) << " -12 -80 -s\n";
			cout << "Example w/o symbols: " << get_file_name(argv[0]) << " -12 -80 -ns\n\n";
			cout << "Password will be automatically copied to your clipboard!\n";
			cout << "###\n";
			return 1;
		}
		if(string(argv[1]) == "-v")
		{
			cout << "Author : Tugberk Kaan Duman\n";
			cout << "Contact: kaan@dumanmail.com\n";
			cout << "Version: 1.5.0\n";
			cout << "###\n";
			return 2;
		}
		if(string(argv[1]) == "-length" || string(argv[1]) == "-l")
		{
			cout << "Try to use the command as:\n";
			cout << get_file_name(argv[0]) << " -8 -98 -ns # for a password that has length of 8 and security score of minimum 98 that doesn\'t include symbols.\n";
			cout << get_file_name(argv[0]) << " -8 -98 -s  # for a password that has length of 8 and security score of minimum 98 that doesn include symbols.\n";
			cout << "###\n";
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
				cout << "###\n";
				return 1;
			}
		}
		for(unsigned int i = 1; i < raw_argument2.length(); i++)
		{
			if(!isdigit(raw_argument2[i]))
			{
				cerr << "Invalid parameters! Use -h to see how to use this program.\n";
				cout << "###\n";
				return 1;
			}
		}
		if(raw_argument1[0] != '-')
		{
			cerr << "Did you mean: " << get_file_name(argv[0]) << " -" << argv[1] << " " << raw_argument2 << " # missing dash before an argument!\n";
			cout << "###\n";
			return 1;
		}
		if(raw_argument2[0] != '-')
		{
			cerr << "Did you mean: " << get_file_name(argv[0]) << " " << raw_argument1 << " -" << argv[2] << " # missing dash before an argument!\n";
			cout << "###\n";
			return 1;
		}
		if(string(argv[1]).empty() || string(argv[2]).empty())
		{
			cerr << "Missing parameters! Use -h to see how to use this program!\n";
			cout << "###\n";
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
				cerr << "Generated password doesn't satisfy required safety level.\n";
				cout << "###\n";
				OpenClipboard(nullptr);
				EmptyClipboard();
				CloseClipboard();
				return 1;
			}
		}
		cout << "Generated password strength: " << password_score(generated_password) << "/100\n";
		cout << "Password symbol status     : " << boolalpha << symbols << "\n";
		cout << "Password has been copied to clipboard!\n";
		cout << "###\n";
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
				cout << "###\n";
				return 1;
			}
		}
		for(unsigned int i = 1; i < raw_argument2.length(); i++)
		{
			if(!isdigit(raw_argument2[i]))
			{
				cerr << "Invalid parameters! Use -h to see how to use this program.\n";
				cout << "###\n";
				return 1;
			}
		}
		for(unsigned int i = 1; i < raw_argument3.length(); i++)
		{
			if(isdigit(raw_argument3[i]))
			{
				cerr << "Invalid parameters! Use -h to see how to use this program.\n";
				cout << "###\n";
				return 1;
			}
		}
		if(raw_argument1[0] != '-')
		{
			cerr << "Did you mean: " << get_file_name(argv[0]) << " -" << argv[1] << " " << raw_argument2 << " " << raw_argument3 << " # missing dash before an argument!\n";
			cout << "###\n";
			return 1;
		}
		if(raw_argument2[0] != '-')
		{
			cerr << "Did you mean: " << get_file_name(argv[0]) << " " << raw_argument1 << " -" << argv[2] << " " << raw_argument3 << " # missing dash before an argument!\n";
			cout << "###\n";
			return 1;
		}
		if(raw_argument3[0] != '-')
		{
			cerr << "Did you mean: " << get_file_name(argv[0]) << " " << raw_argument1 << " " << raw_argument2 << " -" << argv[3] << " # missing dash before an argument!\n";
			cout << "###\n";
			return 1;
		}
		if(string(argv[1]).empty() || string(argv[2]).empty() || string(argv[3]).length() == 0 || string(argv[3]).empty())
		{
			cerr << "Missing parameters! Use -h to see how to use this program!\n";
			cout << "###\n";
			return 1;
		}
		raw_argument1.erase(raw_argument1.begin());
		raw_argument2.erase(raw_argument2.begin());
		const auto first_argument = stoi(raw_argument1);
		const auto second_argument = stoi(raw_argument2);
		auto seconds_since_start = 0;

		auto symbols = false;
		auto clipboard = true;

		if(string(argv[3]) == "-nosym" || string(argv[3]) == "-ns")
		{
			symbols = false;
		}

		if(string(argv[3]) == "-sym" || string(argv[3]) == "-s")
		{
			symbols = true;
		}

		if(string(argv[3]) == "-nsnc" || string(argv[3]) == "-ncns")
		{
			symbols = false;
			clipboard = false;
		}

		if(string(argv[3]) == "-ncs" || string(argv[3]) == "-snc")
		{
			symbols = true;
			clipboard = false;
		}

		const auto start = time(nullptr);
		
		auto generated_password = password_generator(first_argument, symbols, clipboard);
		
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
				cerr << "Generated password doesn't satisfy required safety level.\n";
				cout << "###\n";
				OpenClipboard(nullptr);
				EmptyClipboard();
				CloseClipboard();
				return 1;
			}
		}
		cout << "Generated password strength: " << password_score(generated_password) << "/100\n";
		cout << "Password symbol status     : " << boolalpha << symbols << "\n";
		if(clipboard)
			cout << "Password has been copied to clipboard!\n";
		cout << "###\n";
		return 0;
	}
	if(argc > 4)
	{
		cerr << "Unsupported number of parameters!\n";
		return 1;
	}
	cout << "Commands:\n";
	cout << "1. " << get_file_name(argv[0]) << " -length -security_level -symbol_status # Security level is XYZ out of 100\n";
	cout << "2. " << get_file_name(argv[0]) << " -h\n";
	cout << "3. " << get_file_name(argv[0]) << " -l\n";
	cout << "4. " << get_file_name(argv[0]) << " -v\n";
	cout << "###\n";
}
