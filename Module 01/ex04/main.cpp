/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <cleblais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:48:16 by cleblais          #+#    #+#             */
/*   Updated: 2023/05/12 18:51:01 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int	check_args(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "*** Error: you should put 3 arguments ***" << std::endl;
		std::cout << "[argument 1]	Filename" << std::endl;
		std::cout << "[argument 2]	The string to replace" << std::endl;
		std::cout << "[argument 3]	The replacing string" << std::endl;
		return (1);
	}
	if (!argv[2][0] || !argv[3][0])
	{
		std::cout << "*** Error: the string cannot be empty ***" << std::endl;
		return (1);
	}
	std::string file = argv[1];
	std::ifstream	input_file("./" + file);
	if (!input_file)
	{
		std::cout << "Impossible to open the file" << std::endl;
		return (1);
	}
	return (0);
}


int copy_file(char **argv)
{
	std::string 	file = argv[1];
	
	std::ifstream	input_file("./" + file);
	std::ofstream	output_copied_file("./" + file + ".replace");
	if (!output_copied_file)
	{
		std::cout << "*** Error: impossible to copy the file ***" << std::endl;
		return (1);
	}
	
	char 		c;
	int 		i = 0;
	char 		*old_str = argv[2];
	std::string	new_str = argv[3];
	std::string	buf;
	bool		at_least_one = false;
	
	while (input_file.get(c))
	{
		if (c == old_str[i])
		{
			buf+= c;
			i++;
		}
		else
		{
			if (!old_str[i])
			{
				output_copied_file << new_str << c;
				at_least_one = true;
				i = 0;
				buf = "";
			}
			else
			{
				if (buf != "")
				{
					output_copied_file << buf << c;
					i = 0;
					buf = "";
				}
				else
					output_copied_file << c;
			}
		}
	}
	if (buf != "")
	{
		if (!old_str[i])
		{
			output_copied_file << new_str;
			at_least_one = true;
		}
		else
			output_copied_file << buf;
	}
	input_file.close();
	output_copied_file.close();
	if (at_least_one == false)
		std::cout << "=== Copy done but no string to replace has been found ===" << std::endl;
	else
		std::cout << "=== Copy done ===" << std::endl;
	return (0);
}

int	main(int argc, char **argv)
{
	if (check_args(argc, argv))
		return (1);
	if (copy_file(argv))
		return (1);
	return (0);
}