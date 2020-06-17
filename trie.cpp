// This is a trie data structure implemented in C++
// Author: Prakash Besra
// Created on : 18-06-2020

#include <iostream>
#include <map>
using namespace std;

class TrieNode{
	public:
		bool endOfCharacter;
		map<char, TrieNode*> children;
		
};

class Trie{
	public:
		TrieNode* root;
		Trie(){
			root=new TrieNode();
		}

		void insert(string word){
			TrieNode* current=root;

			for(int i=0;i<word.length();i++){
				char chr=word[i];
				TrieNode* node=current->children[chr];
				if(node==NULL){
					string t="test";
					node=new TrieNode();
					node->endOfCharacter=false;
					current->children[chr]=node;
					
				}
				current=node;

			}
			current->endOfCharacter=true;
		}

		bool search(string word){
			TrieNode* current=root;

			for(int i=0;i<word.length();i++){
				char chr=word[i];
				TrieNode* node=current->children[chr];
				
				if(node==NULL){
					return(false);
				}
				current=node;
			}
			return(current->endOfCharacter);
		}
};

int main(){

	Trie* trie=new Trie();
	trie->insert("abcbc");
	trie->insert("abccc");
	trie->insert("bcaca");
	trie->insert("mcvx");
	trie->insert("mxsx");

	cout << trie->search("mxsx") << endl;
	return(0);
}
