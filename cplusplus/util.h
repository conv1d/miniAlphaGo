/*
	util.h
*/
#pragma once
#include <iostream>
#define TREE_POLICY_C 1.0 //Tree Policy?е????C
#define POOL_RESERVE 320000  //??????????С
#define RANDOM_SEQ_NUM 1000 //??????г??С
#define SWAP_TIME 100 //???????????????????????
#define DEBUG_INFO 0
#define CHECK_INTERVAL 100
#define BUDGET_RATIO 0.95
//#define _INCLUDE_RAVE
#define RAVE_K 1000.0
#define IF_AI_PAUSE 0
#define MAX_STR_BUFFER 100000
#define MAX_RESEND 3
#define SLEEP_TIME 3000
#define SEND_TIMEOUT_SECOND 20
#define RECV_TIMEOUT_SECOND 20
#define SERVER_RETRY 3
#define MIN_CHECK_INTERVAL 2
#define MAX_CHECK_INTERVAL 10000

//?????
typedef struct STreeNode
{
	unsigned long long occ, pla; //occ???????????? pla???????????
	struct STreeNode *child[64],*next,*parent; //child?????????? next???????е?????? parent??????????
	unsigned char childN, expandN; //childN??????????????????????child???飬expandN????????????????????????????????
	bool isBlack; //????????????????
	long total, win; //?????????????????
	unsigned char change;
#ifdef _INCLUDE_RAVE
	unsigned int totalAMAF[64], winAMAF[64];
#endif
}TreeNode;

//??????г?
extern unsigned char **xSeq, **ySeq;

//??????
TreeNode * NewNode(TreeNode *next);	

//???????????1??????0????????-1????
int GetPosition(const unsigned long long &occupied, const unsigned long long &player, unsigned char x, unsigned char y);

//?????????
void SetPosition(unsigned long long &occupied, unsigned long long &player, unsigned char x, unsigned char y, bool isBlack);

//???????
void PrintBoard(const unsigned long long &occupied, const unsigned long long &player);

//??????????????????λ??
int PrintBoardWithHint(const unsigned long long &occupied, const unsigned long long &player,bool isBlack);

//?????λ??
int CountLegalSteps(const unsigned long long &occupied, const unsigned long long &player, bool isBlack);

//??鵥????????????????????????????????????????????????????????
int SingleStep(const unsigned long long &occ, const unsigned long long &pla, unsigned char stepX, unsigned char stepY, bool isBlack, unsigned long long &nextOcc, unsigned long long &nextPla);

//???????????г?
void InitRandomSeq();

//??????????????
void GetRandomSeq(unsigned char **xSeq, unsigned char **ySeq);

//???
void FreeRandomSeq();

//?????? 1????? 0???? -1?????
int CheckWinner(unsigned long long occ,unsigned long long pla);

//????????????е????λ??
int FindDiff(unsigned long long occ0, unsigned long long occ1,unsigned char &x,unsigned char &y);