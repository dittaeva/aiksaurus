/*
 * AikSaurus - An open source thesaurus library
 * Copyright (C) 2001 by Jared Davis
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  
 * 02111-1307, USA.
 *
 */


#include "AikSaurus.h"
#include <iostream>
#include <cstdlib>

using namespace std;

void checkError(const AikSaurus& T)
{
	const char* err = T.error();
	
	if (err[0] != '\0')
	{
		cout << "Error: " << err << endl;
		exit(1);
	}
}


int main()
{
	AikSaurus T;
	checkError(T);
		
	char buf[1024];

	while(true)
	{
		cout << "Look Up: " << flush;
				
		if (!(cin.getline(buf, 1024)))
		{
			// end of file, stop program.
			break;
		}

		if (!T.find(buf))
		{
			cout << "No matches found.  Similar Words:" << endl;
			for(const char* sim = T.similar(); sim[0] != '\0'; sim = T.similar())
			{
				cout << '\t' << sim << endl;
			}
		}

		char code;
		for(const char* result = T.next(code); result[0] != '\0'; result = T.next(code))
		{
			cout << '\t';
			
			cout << ((code & AikSaurus::Noun)		? ('N') : ('-'));
			cout << ((code & AikSaurus::Verb)		? ('V') : ('-'));
			cout << ((code & AikSaurus::Adjective)	? ('J') : ('-'));
			cout << ((code & AikSaurus::Adverb)		? ('D') : ('-'));
			cout << ((code & AikSaurus::Other)		? ('O') : ('-'));
			cout << ((code & AikSaurus::Unknown)	? ('U') : ('-'));
			
			cout << '\t' << result << '\n';
		};

		checkError(T);
	}

	return 0;
}
