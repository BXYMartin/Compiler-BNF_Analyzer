#include<iostream>
#include<math.h>
#include<string>
#include<stdlib.h>
#include<stdio.h>
#include<fstream>
#include<set>
#include<map>
#include<algorithm>

#define SYMBOL  0
#define LEFT    1
#define RIGHT   2
#define COMMA   3

#define EXP     0
#define ELE     1

using namespace std;

typedef struct STreeNode* pSTreeNode;
typedef string TreeDataType;

struct STreeNode
{
    int level;
    TreeDataType data;
    pSTreeNode pFather;
    pSTreeNode pFirstChild;
    pSTreeNode pNextBrother;

    STreeNode( TreeDataType Value, int l )
    {
        level = l;
        data = Value;
        pFather = nullptr;
        pFirstChild = nullptr;
        pNextBrother = nullptr;
    }
};


class CTree
{
public:
    CTree();
    CTree( TreeDataType Value );
    ~CTree();


public:
    void InsertBrother( pSTreeNode fatherNode, pSTreeNode pParentNode, TreeDataType Value, int l );
    int  CheckInsert( TreeDataType parentValue, TreeDataType Value );
    pSTreeNode Search( pSTreeNode pNode, TreeDataType Value );
    void SearchAll( pSTreeNode pNode, TreeDataType Value );
    void StoreSeparate( pSTreeNode pNode);
    void PrintTree( pSTreeNode pNode, int level );
    void FreeMemory( pSTreeNode pNode );
    void SplitBrother( pSTreeNode fatherNode, pSTreeNode pBrotherNode, TreeDataType Value, int l );
    void CutTree( pSTreeNode pNode, set<string> V );
    void deleteFather( pSTreeNode pNode );

public:
    pSTreeNode pRoot;
    int changed = 1;
    set<pSTreeNode> search;
};

CTree::CTree()
{
    pRoot = nullptr;
}

CTree::CTree( TreeDataType Value )
{
    pRoot = new STreeNode( Value, ELE );
    if ( pRoot == nullptr )
        return;
}

CTree::~CTree()
{
    if (pRoot == nullptr )
        return;

    FreeMemory( pRoot );
}

void CTree::FreeMemory( pSTreeNode pNode )
{
    if ( pNode == nullptr )
        return;

    if ( pNode->pFirstChild != nullptr )
        FreeMemory( pNode->pFirstChild );

    if ( pNode->pNextBrother != nullptr )
        FreeMemory( pNode->pNextBrother );

    delete pNode;
}

void CTree::SearchAll( pSTreeNode pNode, TreeDataType Value)
{
    if (pNode == nullptr)
        return;

    if(pNode->data == Value && pNode->level == ELE)
        search.insert(pNode);

    SearchAll( pNode->pFirstChild, Value );
    SearchAll( pNode->pNextBrother, Value );
}

void CTree::InsertBrother( pSTreeNode fatherNode, pSTreeNode pBrotherNode, TreeDataType Value, int l )
{
    if ( pBrotherNode->pNextBrother != nullptr )
        InsertBrother( fatherNode, pBrotherNode->pNextBrother, Value, l );
    else
    {
        pBrotherNode->pNextBrother = new STreeNode( Value, l );
        pBrotherNode->pNextBrother->pFather = fatherNode;
        return;
    }
}

void CTree::SplitBrother( pSTreeNode fatherNode, pSTreeNode pBrotherNode, TreeDataType Value, int l )
{
    if ( pBrotherNode->pNextBrother != nullptr )
        SplitBrother( fatherNode, pBrotherNode->pNextBrother, Value, l );
    else
    {
        pBrotherNode->pNextBrother = new STreeNode( Value, l );
        pBrotherNode->pNextBrother->pFather = fatherNode;
        StoreSeparate(pBrotherNode->pNextBrother);
        return;
    }
}

void CTree::StoreSeparate( pSTreeNode pNode)
{
    string in;
    string expression = pNode->data;
    for(string::iterator j = expression.begin(); j != expression.end(); j++){
        in.clear();
        in.push_back(*j);
        if (pNode->pFirstChild == nullptr) {
            pNode->pFirstChild = new STreeNode(in, ELE);
            pNode->pFirstChild->pFather = pNode;
            continue;
        } else {
            InsertBrother(pNode, pNode->pFirstChild, in, ELE);
            continue;
        }
    }
}

int CTree::CheckInsert( TreeDataType parentValue, TreeDataType Value )
{
    set<string> visited;
    set<string> terminalvisited;
    int flag = 0;
    if ( pRoot == nullptr )
        return 0;
    search.clear();

    SearchAll( pRoot, parentValue );

    if ( search.empty() == true )
        return 0;

    for(set<pSTreeNode>::iterator pFindNode = search.begin();pFindNode != search.end();pFindNode++) {

        pSTreeNode sourceNode = *pFindNode;
        if (sourceNode->pFirstChild != nullptr) {
            sourceNode = sourceNode->pFirstChild;
            visited.insert(sourceNode->data);
        }
        while (sourceNode->pNextBrother != nullptr) {
            sourceNode = sourceNode->pNextBrother;
            visited.insert(sourceNode->data);
        }
        while (sourceNode->pFather != nullptr) {
            sourceNode = sourceNode->pFather;
            visited.insert(sourceNode->data);
        }

        if(visited.count(Value) == 0) {
            flag = 1;
            if ((*pFindNode)->pFirstChild == nullptr) {
                (*pFindNode)->pFirstChild = new STreeNode(Value, EXP);
                (*pFindNode)->pFirstChild->pFather = (*pFindNode);
                StoreSeparate((*pFindNode)->pFirstChild);
                continue;
            } else {
                SplitBrother((*pFindNode), (*pFindNode)->pFirstChild, Value, EXP);
                continue;
            }
        }
    }
    return flag;
}

pSTreeNode CTree::Search( pSTreeNode pNode, TreeDataType Value )
{

    if ( pNode == nullptr )
        return nullptr;

    if ( pNode->data == Value )
        return pNode;

    if ( pNode->pFirstChild == nullptr && pNode->pNextBrother == nullptr )
        return nullptr;
    else
    {
        if ( pNode->pFirstChild != nullptr )
        {
            pSTreeNode pNodeTemp = Search( pNode->pFirstChild, Value );
            if ( pNodeTemp != nullptr )
                return pNodeTemp;
            else
            {
                return Search( pNode->pNextBrother, Value );
            }
        }
        else
            return Search( pNode->pNextBrother, Value );
    }
}

void CTree::PrintTree( pSTreeNode pNode, int level )
{
    if (pNode == nullptr)
        return;
    for(int i = 0; i < level; i++)
        cout << "|- ";
    cout << pNode->data << " " << pNode->level << endl;

    PrintTree( pNode->pFirstChild, level + 1 );
    PrintTree( pNode->pNextBrother, level );
}

void CTree::deleteFather( pSTreeNode pNode ){
    pSTreeNode Temp;
    while(pNode->pFather != nullptr && pNode->pFather->level != EXP){
        pNode = pNode->pFather;
    }

    if(pNode->pFather == nullptr)
        return;

    pNode = pNode->pFather;

    if(pNode->pFather->pFirstChild == pNode){
        cout<< ">> Cut " << pNode->pFather->pFirstChild->data << " Branch" << endl;
        pNode->pFather->pFirstChild = nullptr;
        return;
    }
    else {
        Temp = pNode->pFather->pFirstChild;
        while (Temp->pNextBrother != pNode)
            Temp = Temp->pNextBrother;
        cout << ">> Cut " << Temp->pNextBrother->data << " Branch" << endl;
        Temp->pNextBrother = Temp->pNextBrother->pNextBrother;
        return;
    }
}

void CTree::CutTree( pSTreeNode pNode, set<string> V )
{
    if (pNode == nullptr)
        return;

    if(pNode->pFirstChild == nullptr && V.count(pNode->data) != 0){
        changed = 1;
        deleteFather(pNode);
    }

    CutTree( pNode->pFirstChild, V );
    CutTree( pNode->pNextBrother, V );
}

class Grammar
{
public:
    Grammar();
    Grammar( string txt );
    ~Grammar();

public:
    void GetChar();
    void SkipChar();
    void Concat();
    bool IsLetter();
    bool IsDigit();
    void Retract();
    int Process();
public:
    char ch;
    string token, name, startSYMBOL;
    string text = "G = <{Z, U, C, a, b, c}, {a, b, c}, {Z = U | a, U = a | b | C, C = aCb | bCa}, {Z}>";
    set<string> V, Vn, Vt;
    multimap<string, string> P;
    int Indicator = 0, Starter = 0, pos = 0;
    pair<string, string> p;
};

Grammar::Grammar( string txt )
{
    text = txt;
}

void Grammar::GetChar()
{
    ch = text[pos];
    pos++;
}

void Grammar::SkipChar()
{
    while (1) {
        if (ch == ' ')
            GetChar();
        else
            break;
    }
}

void Grammar::Concat()
{
    token += ch;
}

bool Grammar::IsLetter()
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        return true;
    else
        return false;
}

bool Grammar::IsDigit()
{
    if (ch >= '0' && ch <= '9')
        return true;
    else
        return false;
}

void Grammar::Retract()
{
    ch = ' ';
    pos--;
}

int Grammar::Process() {
    if(pos >= text.length())
        return -1;
    token = "";
    GetChar();
    SkipChar();
    if (IsLetter() || IsDigit() || ch == '_')
    {
        while (IsLetter() || IsDigit() || ch == '_') {  // Put Slash into Consideration
            Concat();
            GetChar();
        }
        Retract();
        return SYMBOL;

    } else if (ch == '{'){
        token = ch;
        return LEFT;
    } else if (ch == '}'){
        token = ch;
        return RIGHT;
    } else if(ch == ','){
        token = ch;
        return COMMA;
    }
    else{
        return Process();
    }
}


void Analyze(Grammar *Analyzer){
    cout << "Target Content in BNF Format:" << endl;
    cout << Analyzer->text << endl;
    cout << endl;
    cout << "---- Starting Analysis ----" << endl;
    Analyzer->Process();
    Analyzer->name = Analyzer->token;

    while (Analyzer->pos < Analyzer->text.length()) {
        switch(Analyzer->Process()){
            case LEFT:
                Analyzer->Indicator++;
                break;
            case SYMBOL:
                switch(Analyzer->Indicator){
                    case 1:
                        Analyzer->V.insert(Analyzer->token);
                        break;
                    case 2:
                        Analyzer->Vt.insert(Analyzer->token);
                        break;
                    case 3:
                        if(Analyzer->Starter == 0) {
                            Analyzer->Starter++;
                            Analyzer->p.first = Analyzer->token;
                            break;
                        }
                        Analyzer->Starter++;
                        Analyzer->p.second = Analyzer->token;
                        Analyzer->P.insert(Analyzer->p);
                        break;
                    case 4:
                        Analyzer->startSYMBOL = Analyzer->token;
                        break;
                }
                break;
            case COMMA:
                Analyzer->Starter = 0;
                break;
            default:
                break;
        }
    }

    set_difference(Analyzer->V.begin(), Analyzer->V.end(), Analyzer->Vt.begin(), Analyzer->Vt.end(), inserter(Analyzer->Vn, Analyzer->Vn.begin()));
    cout << Analyzer->P.size() << " Rules, ";
    cout << "Started with " << Analyzer->startSYMBOL << ": " << endl;
    for(multimap<string, string>::iterator j=Analyzer->P.begin(); j != Analyzer->P.end(); j++)
    {
        cout<<j->first<<" := "<<j->second<<endl;
    }
    cout << endl;
    cout << "---- Grammar Tree for "<< Analyzer->name << " ----" << endl;
}

int main()
{
    int temp;
    Grammar *Analyzer = new Grammar("G = <{Z, U, C, a, b, c}, {a, b, c}, {Z = U | a, U = a | b | C, C = aCb | bCa}, {Z}>");

    /*
     * Analyze the Grammar
     */
    Analyze(Analyzer);

    CTree* pTree = new CTree(Analyzer->startSYMBOL);

    /*
     * Construct the Tree
     */
    while(pTree->changed != 0) {
        pTree->changed = 0;
        for (multimap<string, string>::iterator j = Analyzer->P.begin(); j != Analyzer->P.end(); j++) {
            temp = pTree->CheckInsert(j->first, j->second);
            pTree->changed = pTree->changed + temp;
        }
    }

    /*
     * Show the Tree
     */
    cout << endl;
    cout << "Original Grammar Tree: " << endl;
    pTree->PrintTree( pTree->pRoot, 0 );
    cout << endl;

    /*
     * Cut the Tree
     */
    cout << "---- Working on the Tree ----" << endl;
    pTree->changed = 1;
    while(pTree->changed != 0) {
        pTree->changed = 0;
        pTree->CutTree( pTree->pRoot, Analyzer->Vn );
    }

    /*
     * Print Again
     */
    cout << endl;
    cout << "After Cleaning Grammar Tree: " << endl;
    pTree->PrintTree( pTree->pRoot, 0 );
    cout << endl;

    delete pTree;
    return 0;
}