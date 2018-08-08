/*
 * Code used for SHA512 hashing.
 * Made some modefications in code borrowed from https://ubuntuforums.org/archive/index.php/t-337664.html#navbar user 'TomChuk' ( Thanks buddy , get in touch for a more formal credit)
 */

#include <gcrypt.h>
#include <iostream>

string sha( string data){

	int msg_len = data.length();
	int hash_len = gcry_md_get_algo_dlen( GCRY_MD_SHA512 );

	unsigned char hash[ hash_len ];

	char out[hash_len*2 + 1];
	char *p = out;

	gcry_md_hash_buffer( GCRY_MD_SHA512, hash, data.c_str() , msg_len );

	for ( int i = 0; i < hash_len; i++, p += 2 ) {
		snprintf ( p, 3, "%02x", hash[i] );
	}

	return string(out);

}

