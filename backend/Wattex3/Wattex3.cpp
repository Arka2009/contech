#include "graphviz/gvc.h"
#include "graphviz/cgraph.h"
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <ecotools/errordefs.h>
#include "../../common/taskLib/Task.hpp"
#include "../CommTracker/CommTracker.hpp"
#include "../../common/taskLib/TaskGraphInfo.hpp"

using namespace contech;

std::ostream& operator<<(ostream& out, const BasicBlockInfo &bbi) {
    out << "{LineNumber:" << bbi.lineNumber 
        << ",functionName:" << bbi.functionName 
        << ",callsFunction:"<< bbi.callsFunction 
        << ",numOfMemOps:" << bbi.numOfMemOps
        << ",numOfOps:" << bbi.numOfOps
        << ",fileName:" << bbi.fileName
        <<"}";
}

int main() {
    const char *fileName = "/home/amaity/Desktop/kmeansOpenMP/tg_kmeansApp";
    TaskGraph *tg = TaskGraph::initFromFile(fileName);

    /* Work0 
     * -----
     * Iterate over the task graph
     */
    // Task* currentTask = NULL;
    // while (currentTask = tg->readContechTask()) {
    //     if (currentTask->getBBCount() > 0) {
    //         std::cout << "TaskId|" << currentTask->getTaskId() \
    //                   << ",Type|"  << currentTask->getType() \
    //                   << ",NumBB|" << currentTask->getBBCount() << "\n";
    //         // break;
    //     }
    // }

    /* Work1 
     * -----
     * Find all the unique BBs in the entire and for each task 
     * emit the set of BB and their multiplicity
     * CHECK backend/stats.cpp
     */
    std::set<uint> uniqueBasicBlockIds;
    uint totalBBTasks = 0, totalTasks = 0;
    bool breakFlag = false;
    TaskGraphInfo* tgi = tg->getTaskGraphInfo();
    while(Task* currentTask = tg->getNextTask()) {
        if (breakFlag)
            break;
        
        switch(currentTask->getType()) {
            case task_type_basic_blocks: {
                std::cout << "StringRep|" << currentTask->getTaskId() << "\n";
                auto bba = currentTask->getBasicBlockActions();
                for (auto f = bba.begin(), e = bba.end(); f != e; ++f) {
                    BasicBlockAction bb = *f;
                    // auto bbi = tgi->getBasicBlockInfo((uint)bb.basic_block_id);
                    std::cout << (uint)bb.basic_block_id << "\n";
                }
                // breakFlag = true;
                std::cout << "\n\n";
            }
            default : break;
        }
        totalTasks++;
    }
    // for (uint uniqueBB : uniqueBasicBlockIds) {
    //     std::cout << uniqueBB << std::endl;
    // }
    // std::cout << "Total tasks : " << totalTasks << std::endl;
    // std::cout << "Total BB tasks : " << totalBBTasks << std::endl;
    // std::cout << "(Doubtful) Total unique BBs : " << uniqueBasicBlockIds.size()<< std::endl;
}