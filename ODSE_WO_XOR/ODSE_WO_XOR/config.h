/*-------------------------------------------------------------------------------%
% Version: 1.00                                                                  %
%                                                                                %
% Description:    Configuration parameters for ODSE with XOR-based PIR  	     %
%                                                                                %
% History Information                                                            %
%   Person                      Date            Comment                          %
%--------------------------------------------------------------------------------%
%   Name               			YYYY-MM-DD    	Description		                 %
%   Thang Hoang                 2016-09-13      File created                     %
%--------------------------------------------------------------------------------*/


#ifndef ODSE_PARAM_H
#define ODSE_PARAM_H

#include "ODSE_Hashmap_Key_Class.h"	
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <functional>
#include <iostream>
#include <fstream>
#include <sstream>
#include <bitset>
#include <vector>
#include <iterator>	
#include <dirent.h>	
#include <sys/stat.h>
#include <unistd.h>
#include <set>
#include <sparsehash/dense_hash_map>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string.hpp>
#include "climits"
#include <chrono>
#include <map>
#include "NTL/ZZ.h"




#define ENCRYPT_BLOCK_SIZE 64
#define MAX_NUM_OF_FILES 12544
#define MAX_NUM_KEYWORDS MAX_NUM_OF_FILES

#define WRITE_ORAM_LAMBDA 30

#define INTEL_AES_NI

#define NUM_SERVERS 2


const std::string SERVER_ADDR[NUM_SERVERS] = {"tcp://localhost:", "tcp://localhost:"};
const std::string SERVER_PORT[NUM_SERVERS] = {"5555","5556"};





using namespace NTL;
using namespace std;	
using google::dense_hash_map;
using namespace boost::algorithm;



static const string gcsClientStatePath = "../data/state/";
static const string gcsEncryptedIdxPath = "../data/EIDX/";
static const string gcsFilepath = "../data/DB/";			                // path of input database
static const string gcsUpdateFilepath = "../data/update/";                  // Path of updated file




#define MATRIX_PIECE_COL_SIZE  MATRIX_COL_SIZE 
#define MATRIX_PIECE_ROW_SIZE MATRIX_ROW_SIZE




#define COL 1
#define ROW 2

#define ZERO_VALUE 0
#define ONE_VALUE 1

#define BYTE_SIZE 8
#define TRAPDOOR_SIZE 16   
#define BLOCK_CIPHER_SIZE 16
#define MATRIX_ROW_SIZE MAX_NUM_KEYWORDS

//Loading factors in hash table before resizing
#define FILE_LOADING_FACTOR 0.5
#define KEYWORD_LOADING_FACTOR 0.5



#define MATRIX_COL_SIZE ((MAX_NUM_OF_FILES/BYTE_SIZE)*2)	
#define NUM_BLOCKS (MATRIX_COL_SIZE*BYTE_SIZE/ENCRYPT_BLOCK_SIZE)	


//Commands for Client - Server interaction
#define CMD_SEND_ENCRYPTED_INDEX         0x000010
#define CMD_LOADSTATE                   0x000011
#define CMD_SAVESTATE                   0x000012
#define CMD_SEARCH_OPERATION            0x000020
#define CMD_DOWNLOAD_COLUMN_BLOCK       0x000050
#define CMD_UPLOAD_COLUMN_BLOCK         0x000060
#define CMD_SUCCESS                     "CMD_OK"




//define the default filename of some data structures in ODSE
#define FILENAME_BLOCK_COUNTER_ARRAY    "block_counter_arr"
#define FILENAME_TOTAL_KEYWORDS_FILES   "keywords_files"
#define FILENAME_SEARCH_RESULT          "search_result"
#define FILENAME_STASH                  "stash"

#define KEYWORD_NOT_EXIST MAX_NUM_KEYWORDS+1
#define FILE_NOT_EXIST MATRIX_COL_SIZE*BYTE_SIZE+1
#define FILE_IN_STASH MATRIX_COL_SIZE*BYTE_SIZE+2

 
#define SOCKET_BUFFER_SIZE              256

//MACROS
#define BIT_READ(character, position, the_bit)	((*the_bit = *character & (1 << position)))	
#define BIT_SET(character, position) ((*character |= 1 << position))	
#define BIT_CLEAR(character, position) ((*character &= ~(1 << position)))
#define BIT_TOGGLE(character, position)	((*character ^= 1 << position))
#define BIT_CHECK(var,pos) !!((*var) & (1<<(pos)))


static const string gcsKwHashTable = "kw_hashtable";
static const string gcsFileHashTable = "file_hashtable";
static const string gcsListFreeFileIdx = "lstFreeFileIdx";
static const string gcsListFreeKwIdx = "lstFreeKwIdx";


// Delimiter separating unique keywords from files 		
const char* const delimiter = "`-=[]\\;\',./~!@#$%^&*()+{}|:\"<>? \n\t\v\b\r\f\a";	

typedef unsigned long  TYPE_COUNTER;
typedef unsigned long  TYPE_INDEX;
typedef dense_hash_map<hashmap_key_class,TYPE_INDEX,hashmap_key_class,hashmap_key_class> TYPE_GOOGLE_DENSE_HASH_MAP;
typedef std::set<string> TYPE_KEYWORD_DICTIONARY;

#include "struct_StashData.h"
typedef vector<STASH_DATA> STASH;

static TYPE_KEYWORD_DICTIONARY keywords_dictionary;

#define time_now std::chrono::high_resolution_clock::now()

typedef unsigned long long int TYPE_REGISTER;
#endif
