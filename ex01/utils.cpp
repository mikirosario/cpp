/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 17:31:46 by mrosario          #+#    #+#             */
/*   Updated: 2021/10/03 15:50:09 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/*
** This function is for buffer overflow handling.
**
** I don't like allowing the user to input an unlimited number of characters to
** my buffer, so I restrict field lengths. I use cin.getline(buff, BUFSIZE) to
** control this. If the user inputs more than BUFSIZE-1 characters for a given
** buffer, getline will extract only up to BUFSIZE-1 characters and ignore the
** rest. The cin.getline function uses a cstring buffer, and cstrings are always
** null-terminated, hence the -1. The BUFSIZE includes the null terminator. The
** rest of the user input will remain in the cin buffer. This function is to
** handle the resulting situation so the cin buffer is cleared and ready for
** new user input.
**
** If getline extracts no characters OR no delimiting character ('\n' by
** default) is found after BUFSIZE-1 characters are read, it will set the fail
** bit of the cin instance (which we can detect by using the cin.fail member
** function). The gcount member function of cin will return the number of
** characters extracted in the last unformatted input operation on the cin
** object (i.e. the getline function, in this case).
**
** Thus, if the fail bit is set AND the gcount is BUFSIZE-1, we know the user
** input was bigger than our buffer and truncated by getline, which means the
** cin buffer needs to be cleared. So first we test for this condition.
**
** If we don't clear the cin buffer, it causes infinite looping. This seems to
** be related to the fail bit. I think that if the fail bit isn't reset, the
** cin.getline function just keeps failing over and over again, causing the
** input loop to loop infinitely.
**
** To prevent this, I use cin.clear member function, which clears the fail bit,
** and then I use cin.ignore up to the streamsize max limit or until the next
** '\n' to ignore everything else accumulated in the cin buffer, so that it
** isn't extracted in subsequent input loops.
**
** Whew. Done!
**
** Then I return 0 or 1 to indicate whether an overflow occurred for further
** optional handling by the calling function, as desired.
*/

int		cin_buff_overflow(int bufsize)
{
	if (std::cin.fail() && std::cin.gcount() == bufsize-1)
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return (1);
	}
	return (0);
}
