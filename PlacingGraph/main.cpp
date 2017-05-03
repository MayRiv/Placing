/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: i.Maydanovskiy
 *
 * Created on 28 апреля 2017 г., 15:51
 */

#include <cstdlib>
#include <set>
#include <iostream>
#include <vector>
using namespace std;

/*
 * 
 */
const int N = 10;
int playersConnections[N*N][N*N];
struct Node
{
    int value;
    set<Node*> childs;
};
class Graph
{
public: 
    Graph(int tablesNumber)
    {
        this->tablesNumber = tablesNumber;
    }
    void init()
    {
        vector<int> placing;
        placing.reserve(N*N);
        for (int i = 0; i < N*N; i++)
            placing.push_back(i);
        acquaint(placing);
    }
    vector<int> build()
    {
        set<int> remainder;
        for(int i = 1; i < N*N; i ++){
            remainder.insert(i);
        }
        Node* root = new Node;
        root->value = 0;
        set<int> table;
        table.insert(0);
       
        build(root, remainder, table, N*N);
        cout << "Builded" << endl;
        vector<int> placing;
        placing.reserve(N*N);
        for (int i = 0; i < N*N; i++)
            placing.push_back( -1);
        collapse(root, placing, 0);
        cout << "Collapsed" << endl;
        acquaint(placing);
        cout << "Acquainted" << endl;
        //clean(root);
        cout << "Cleaned" << endl;
        return placing;
    }
    void clean(Node* node)
    {
        for (set<Node*>::iterator it = node->childs.begin(); it != node->childs.end(); it++)
        {
            clean(*it);
        }
        delete node;
    }
    bool collapse(Node* node, vector<int>& placing, int level)
    {
        if (level == N*N - 1)
        {
            placing[level] = node->value;
            return true;
        }
        for (set<Node*>::iterator it = node->childs.begin(); it != node->childs.end(); it++)
        {
            if (collapse(*it, placing, level + 1))
            {
                placing[level] = node->value;
                return true;
            }
        }
        return false;
    }
    void showTable()
    {
        for(int i = 0; i < N*N; i++)
        {
            for(int j = 0; j < N*N; j++)
            {
               cout << playersConnections[i][j] << " ";
            }
            cout << endl;
        }
    }
private:
    int tablesNumber;
    bool build(Node* node, set<int> remainder, set<int> table, int level)
    {
        if (level > 1)
        {
            for(set<int>::iterator it = remainder.begin(); it != remainder.end(); it++)
            {
                if (!isAcquaint(*it, table))
                {
                    Node* n = new Node;
                    n->value = *it;
                    node->childs.insert(n);
                    set<int> newTable, newRemainder;
                    if (table.size() < N-1)
                    {
                        newTable = table;
                        newTable.insert(*it);
                    }
                    newRemainder = remainder;
                    newRemainder.erase(*it);
                    if (build(n,newRemainder, newTable, level -1))
                        return true;
                    //build(n,newRemainder, newTable, level -1);
                }
                
            }
            return false;
        }
        else
        {
            return true;
        }
    }
    
    bool isAcquaint(int number, set<int> table)
    {
        for(set<int>::iterator it = table.begin(); it != table.end(); it++)
        {
            if (playersConnections[number][*it])
                return true;
        }
        return false;
    }
    void acquaint(vector<int> placing)
    {
        for (int  k =1; k < N + 1  ; k ++)
        {
            for (int i = (k-1)*N; i < N*k - 1; i++)
            {
                for(int j = i + 1; j < N*k; j++)
                {
                    playersConnections[placing[i]][placing[j]] = 1;
                    playersConnections[placing[j]][placing[i]] = 1;
                }
            }
        }
    }
    
};





int main(int argc, char** argv) {

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            playersConnections[i][j] = 0;
    Graph g(N);
    g.init();
    cout << "inited" << endl;
    vector<int> placing1 = g.build();
    cout << "ready first" << endl;
    vector<int> placing2 = g.build();
    cout << "ready second" << endl;
    vector<int> placing3 = g.build();
    cout << "ready third" << endl;
    vector<int> placing4 = g.build();
    cout << "ready fourths" << endl;
    vector<int> placing5 = g.build();
    cout << "ready 5" << endl;
    vector<int> placing6 = g.build();
    cout << "ready 6" << endl;
    vector<int> placing7 = g.build();
    cout << "ready 7" << endl;
    vector<int> placing8 = g.build();
    cout << "ready 8" << endl;
    vector<int> placing9 = g.build();
    cout << "ready 9" << endl;
    vector<int> placing10 = g.build();
    cout << "ready 10" << endl;
    vector<int> placing11 = g.build();
    cout << "ready 11" << endl;
    cout << "ready";
    return 0;
}

