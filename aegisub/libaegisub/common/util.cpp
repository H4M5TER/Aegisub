// Copyright (c) 2011, Amar Takhar <verm@aegisub.org>
//
// Permission to use, copy, modify, and distribute this software for any
// purpose with or without fee is hereby granted, provided that the above
// copyright notice and this permission notice appear in all copies.
//
// THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
// WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
// ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
// WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
// ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
// OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
//
// $Id$

/// @file util.cpp
/// @brief Unix utility methods.
/// @ingroup libaegisub

#ifndef LAGI_PRE
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#include <climits>
#include <locale>
#endif


#include "libaegisub/util.h"

namespace agi {
	namespace util {


void str_lower(std::string &str) {
	std::locale loc;
	for (size_t i=0; i < str.length(); ++i) {
		str[i] = std::tolower(str[i], loc);
	}
}


int strtoi(std::string &str) {
	long l = strtol(str.c_str(), NULL, 10);

	if ((errno == ERANGE) || (l < INT_MIN) || (l > INT_MAX))
		return 0;

	return (int)l;
}


	} // namespace util
} // namespace agi
