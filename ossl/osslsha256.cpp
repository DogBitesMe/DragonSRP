/* ===============================================================  @
*  DragonSRP, C++ library implementing Secure Remote Protocol       *
*  Copyright (C) 2011 Pavel Slechta                                 *
*  <slechta@email.cz>                                               *
*                                                                   *
*  DragonSRP is free software; you can redistribute it and/or       *
*  modify it under the terms of the GNU Lesser General Public       *
*  License as published by the Free Software Foundation; either     *
*  version 3 of the License, or (at your option) any later version. *
*                                                                   *
*  DragonSRP is distributed in the hope that it will be useful,     *
*  but WITHOUT ANY WARRANTY; without even the implied warranty of   *
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU *
*  Lesser General Public License for more details.                  *
*                                                                   *
*  You should have received a copy of the GNU Lesser General Public *
*  License along with DragonSRP.                                    *
*  If not, see <http://www.gnu.org/licenses/>.                      *
@  =============================================================== */


/* ===============================================================  @
*  This product includes software developed by the OpenSSL Project  *
*  for use in the OpenSSL Toolkit. (http://www.openssl.org/)        *
*                                                                   *
*  This product includes cryptographic software                     *
*  written by Eric Young (eay@cryptsoft.com)                        *
*                                                                   *
*  This product includes software                                   *
*  written by Tim Hudson (tjh@cryptsoft.com)                        *
@  =============================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <openssl/sha.h>

#include "osslsha256.hpp"
#include "dsrp/conversion.hpp"

namespace DragonSRP
{
	OsslSha256::~OsslSha256()
	{
		// empty
	}
	
	bytes OsslSha256::hash(const bytes &in)
	{
		int len;
		unsigned char *arr = Conversion::bytes2array(in, &len);
	
		SHA256_CTX context;
		unsigned char md[SHA256_DIGEST_LENGTH];
		
		SHA256_Init(&context);
		SHA256_Update(&context, arr, len);
		SHA256_Final(md, &context);
		
		bytes ret = Conversion::array2bytes(md, SHA256_DIGEST_LENGTH);
		
		free(arr);
		return ret;
	}
	
	unsigned int OsslSha256::outputLen()
	{
		return SHA256_DIGEST_LENGTH;
	}
}
