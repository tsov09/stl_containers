
#include <iostream>
#include<string>
#include <stdlib.h>
#include <time.h>
#include <bits/stdc++.h>

#include "forward_list.h"
#include "vector.h"
#include "hash_table.h"


int main()
{
	int vec_size = 7;

	Hash_Table<int> tbl;
	for (int i = 0; i < 15; i++) {
		tbl.insert(i);
	}
	tbl.print();

	//delete tbl;
	return 0;
}