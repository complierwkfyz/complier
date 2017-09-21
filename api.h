//
//  api.h
//
//  Created by leeshengyuan on 2017/9/21.
//  Copyright © 2017年 leeshengyuan. All rights reserved.
//
#pragma once
#include <stdio.h>
//nfa边
typedef struct
{
    //起始状态
    unsigned start;
    //转换成的状态
    unsigned end;
    //转换经过的字符,0表示无条件转换
    char cond;
}nfa_edge;

//可结束状态(即在遇到文件结尾时只有遇到这种状态才是可以接受的)
typedef struct
{
    //结束状态
    unsigned status;
    //结束名
    char name[32];
}finish_node;

//nfa
typedef struct
{
    //nfa边的数组
    nfa_edge *edges;
    //数组长度
    size_t edge_num;
    //结束状态数组
    finish_node *f_nodes;
    //数组长度
    size_t node_num;
}nfa;

/*
 dfa说明，状态码0为预留表示改边不存在或者说该状态无法接受该字符，此时意味着应该已经识别出一个词了
 或者说转换之前的状态应该是可结束状态.
 */
typedef struct{
    //状态表二维数组
    unsigned (*map)[256];
    //二维数组第二维长度(状态个数)
    size_t height;
    //结束状态数组
    finish_node *f_nodes;
    //数组长度
    size_t fns_num;
}dfa;

//释放dfa资源
void free_dfa(dfa a);

//解析文件in,并将输出结果以词对应字符串，词类型(即结束名)
void file_any(FILE *in,dfa a,FILE *out);

//将nfa转换成dfa
dfa nfa_to_dfa(nfa a);
