#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include  <vector>
#include  <list>
#include  <algorithm>

//I use hashset (plug in) to code it
#include  "hash.h"
#include  "hash.cpp"

using namespace std;

class hash_function
{
public:
	hash_function() {}

	// 哈希散列涵数，返回计算后的散列地址
	unsigned int operator()( const string& s )  const 
	{

		unsigned int h	= 0;
		const char* pStr = s.c_str();

		// 置乘法器为hashset类中素数数组prime_list中第一个元素值(53)
		for( ; *pStr; ++pStr )
			h = prime_list[0] * h + *pStr;

		return h;
	}
};

class equality
{
public:
	equality() {}
	bool  operator()( const string& A, const string& B )  const 
	{
		return  (A == B);
	}
};

class Dictionary: public HashSet<string, hash_function, equality> 
{
public:

	// 导入字典文件(wordlist.txt)内容到哈希表中
	Dictionary( string strFilename ) : HashSet<string, hash_function, equality>()
	{
		// 打开字典文件
		ifstream inf( strFilename.c_str() );
		if( !inf ) 
		{
			cerr << "Could not open dictionary:" << strFilename << "\n";
			return;
		}

		while( inf ) 
		{
			// 从输入文件流中读取一行
			string line;
			getline(inf, line);

			// 将从字典文件中读取的每一行插入哈希表中(父类HashSet中)
			insert( line );

			// 输出导入字典的过程
			//			cout << line << endl;
		}
	}

};
void lower( string& s );
string strip_punct( const string& s );
void check_spelling( ifstream& in, Dictionary& dict );


int main() 
{
	 int argc;
	 char* argv[];

	// 如果命令行参数不对，提示错误信息
	if (argc != 3) 
	{
		cerr << "Usage: " << argv[0] << " wordlist_filename input_file\n";
		return EXIT_FAILURE;
	}

	ifstream inf(argv[2]);
	if (! inf) 
	{
		cerr << "Could not open " << argv[2] << "\n";
		return EXIT_FAILURE;
	}

	// 开始导入字典到哈希表中
	cout << "Loading dictionary, this may take awhile...\n";

	Dictionary d(argv[1]);

	check_spelling(inf, d);

	inf.close();

	// 调试时起暂停作用
	system("pause");

	return EXIT_SUCCESS;
}

// 单词内全部字母两两交换后，在字典中查找是否正确，正确则输出，否则
// 继续上述操作直到全部交换过为止
void AllLetter_Swap( int nPos, const string& word, Dictionary& dict )
{
	// 直到单词最后一个字母，结束递归
	if( nPos == word.length() )
		return;

	string strWord;
	char chLetter = word[nPos];
	for( int j = nPos+1; j < word.length(); ++j )
	{
		// 恢复原始单词值
		strWord			= word;

		// 互换指定nPos位置与其后字母
		strWord[nPos]	= strWord[j];
		strWord[j]		= chLetter;

		// 字典中查找，找到输出
		if( dict.search( strWord ) )
			cout << "\t\t" << strWord << endl;
	}

	// 递归调用
	AllLetter_Swap( nPos+1, word, dict);
}

// 单词内相邻两字母交换后，在字典中查找是否正确，正确则输出，否则
// 继续上述操作直到最后两字母交换过为止
void AdjacentLetter_Swap( const string& word, Dictionary& dict )
{
	string strWord;
	for( int nPos = 0; nPos < word.length()-1; ++nPos )
	{
		// 恢复原始单词值
		strWord	= word;

		// 两相邻字母互换(当前字母与相邻后面一个字母互换)
		char chLetter	= word[nPos];
		strWord[nPos]	= strWord[nPos+1];
		strWord[nPos+1]	= chLetter;

		// 字典中查找，找到输出
		if( dict.search( strWord ) )
			cout << "\t\t" << strWord << endl;
	}
}

// 逐次删除单词中每个字母后，在字典中查找是否正确，正确则输出
void RemoveLetter( const string& word, Dictionary& dict )
{
	vector<string> vecWord;		// 存放删除单词字母后，正确单词的数组,用于避免有重复的正确单词输出
	string strWord;
	for( int nPos = 0; nPos < word.length(); ++nPos )
	{
		// 恢复原始单词值
		strWord	= word;

		// 删除一个字母
		strWord.erase( nPos, 1 );

		// 字典中查找，找到输出
		if( dict.search( strWord ) )
		{
			// 在前一次正确单词的数组中查找，如果存在的话，不再输出和压入到数组
			vector<string>::iterator Iter = vecWord.begin();
			for( ; Iter != vecWord.end(); ++Iter )
			{
				if( (*Iter) == strWord )
					break;
			}

			// 否则不存在，则压入该正确单词到数组并输出
			if( Iter == vecWord.end() )
			{
				vecWord.push_back( strWord );
				cout << "\t\t" << strWord << endl;
			}
		}
	}
}

// 逐次替换单词中每个字母为其它一个字母，在字典中查找是否正确，正确则输出
void ReplaceLetter( const string& word, Dictionary& dict )
{
	string strWord;
	string strAlpha = "abcdefghigklmnopqrstuvwxyz";		// 26个小写字母
	for( int nPos = 0; nPos < word.length(); ++nPos )
	{
		// 单词中逐次将每位字母用26个字母代替，判断是否正确单词
		for( int nAlpha = 0; nAlpha < strAlpha.length(); ++nAlpha )
		{
			// 恢复原始单词值
			strWord	= word;

			// 将单词strWord中nPos位置开始的1个字母，用字母串
			// strAlpha中的nAlpha位置开始的1个字母代替
			strWord.replace( nPos, 1, strAlpha, nAlpha, 1 );

			// 字典中查找，找到输出
			if( dict.search( strWord ) )
				cout << "\t\t" << strWord << endl;
		}

	}
}

// 逐次在单词中任意位置，插入任意一个字母后，在字典中查找是否正确，正确则输出
void InsertLetter( const string& word, Dictionary& dict )
{
	vector<string> vecWord;								// 存放插入单词字母后，正确单词的数组,用于避免有重复的正确单词输出
	string strWord;
	string strAlpha = "abcdefghigklmnopqrstuvwxyz";		// 26个小写字母
	for( int nPos = 0; nPos < word.length(); ++nPos )
	{
		// 单词中逐次在每个位置中插入26个字母中一个后，判断是否正确单词
		for( int nAlpha = 0; nAlpha < strAlpha.length(); ++nAlpha )
		{
			// 恢复原始单词值
			strWord	= word;

			// 从单词strWord中nPos位置开始，插入字母串
			// strAlpha中的nAlpha位置开始的1个字母
			strWord.insert( nPos, strAlpha, nAlpha, 1 );

			// 字典中查找，找到输出
			if( dict.search( strWord ) )
			{
				// 在前一次正确单词的数组中查找，如果存在的话，不再输出和压入到数组
				vector<string>::iterator Iter = vecWord.begin();
				for( ; Iter != vecWord.end(); ++Iter )
				{
					if( (*Iter) == strWord )
						break;
				}

				// 否则不存在，则压入该正确单词到数组并输出
				if( Iter == vecWord.end() )
				{
					vecWord.push_back( strWord );
					cout << "\t\t" << strWord << endl;
				}
			}
		}

	}
}

// 单词与哈希表中字典对照，进行拼写检查
void check_spelling( ifstream& in, Dictionary& dict ) 
{

	int line_number = 0;

	while (in) 
	{

		line_number++;

		// 从测试文件中读入一行
		string line;
		getline(in, line);

		// 将读入行放入stringstream中
		stringstream ss (stringstream::in | stringstream::out);
		ss << line;

		// 利用stringstream将一行字符串中每一单词自动提取出来到word中
		string word;
		while (ss >> word) 
		{
			// 将提取出单词转成小写，并去掉可能存在的尾部标点
			lower( word );
			word = strip_punct( word );

			// 在哈希字典里查找这个单词是否存在，存在表示该单词正确，
			// 直接结束本次循环，读取下一个单词重复以上操作
			if( dict.search( word ) )
				continue;

			// 否则在字典里没找到，表示该单词是错误的，输出并推荐输出可能正确的单词
			cout << "line " << line_number << ": '" << word << "'" << endl;
			cout << "\t" << "suggestions:" << endl;

			// 1. 单词中全部字母两两互换后，判断是否正确单词
			//			AllLetter_Swap( 0, word, dict );
			// 1. 单词中相邻两字母互换后，判断是否正确单词
			AdjacentLetter_Swap( word, dict );

			// 2. 删除单词中单个字母后，判断是否正确单词
			RemoveLetter( word, dict );

			// 3. 逐次替换单词中每个字母为其它字母，判断是否正确单词
			ReplaceLetter( word, dict );

			// 4. 逐次在单词中任意位置，插入任意一个字母后，判断是否正确单词
			InsertLetter( word, dict );
		}

	}

}

// 将单词字符串转换为小写字符串
void lower( string& s ) 
{
	for (int i = 0; i < s.length(); i++) 
	{
		s[i] = tolower(s[i]);
	}
}

// 删除单词字符串尾部可能存在的标点符号
string strip_punct( const string& s ) 
{

	if ( ispunct(s[s.length() - 1]) ) 
	{
		return s.substr (0, s.length() - 1);
	}
	else 
	{
		return s;
	}
}
