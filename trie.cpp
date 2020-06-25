// This is a trie data structure implemented in C++
// Author: Prakash Besra
// Created on : 18-06-2020

#include <iostream>
#include <map>
using namespace std;

class TrieNode{
	public:
		// every node in the trie will have these two attributes
		// endOfCharacter has false value by default
		bool endOfCharacter;
		map<char, TrieNode*> children;
		
};

class Trie{
	public:
		// root is the topmost default node of the trie data structure
		TrieNode* root;
		Trie(){
			root=new TrieNode();
		}
		
		// insert a word into trie, Time complexity: O(n), where n=length of word
		void insert(string word){
			
			// initially, current is root
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
				
				// update current to node
				current=node;

			}
			
			// at the end, mark endOfCharacter as true
			current->endOfCharacter=true;
		}

		// search a word in trie, Time complexity: O(n), where n is the length of word.
		// if word is found in the trie, return true, else return false
		bool search(string word){
			TrieNode* current=root;

			for(int i=0;i<word.length();i++){
				char chr=word[i];
				TrieNode* node=current->children[chr];
				
				// if node is null, that means exact word is not present in trie
				if(node==NULL){
					return(false);
				}
				current=node;
			}
			return(current->endOfCharacter);
		}
	// it will mark leaf endOfCharacter as false for independent word and delete all the nodes
	// if the word shares characters with some other word, the it will mark leaf endOfCharacter as false
	bool deleteWord(string word, TrieNode* current, int currentLen){
			
			if(currentLen==word.length()){
				if(current->endOfCharacter){
					current->endOfCharacter=false;
				}
				if(current->children.size()==0){
					delete current;
					current=NULL;
					return(true);
				}
				return false;
			}

			char chr=word[currentLen];
			TrieNode* node=current->children[chr];

			if(node==NULL){
				return false;
			}
			bool shouldDeleteCurrentChildren=deleteWord(word, node, currentLen+1);
			if(shouldDeleteCurrentChildren){

				current->children.erase(chr);
				if(current->children.size()==0){
					delete current;
					current=NULL;
					return(true);
				}
				
				return false;
			}
			
			
			return false;
		}
		void deleteTriedWord(string word){ 
			deleteWord(word,root, 0);
		}
};

int main(){
	
	// create Trie instance to access methods from Trie class
	Trie* trie=new Trie();
	trie->insert("abcbc");
	trie->insert("abccc");
	trie->insert("bcaca");
	trie->insert("mcvx");
	trie->insert("mxsx");

	cout << trie->search("mxsx") << endl;
	trie->deleteTriedWord("abcbc");
	return(0);
}
