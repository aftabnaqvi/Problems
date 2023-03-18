//
//  TopologicalSort.cpp
//  Interview2023
//
//  Created by Syed Naqvi on 3/13/23.
//

#include "TopologicalSort.hpp"

#include <list>
#include <string>
#include <vector>
#include <iostream>

class Node{
public:
    Node(std::string name)
    {
        _name = name;
    }
    
    std::string name()
    {
        return _name;
    }
    
    int data()
    {
        return _data;
    }
    
    void addUpDep(std::string dep)
    {
        _upDepList.push_back(dep);
    }
    
    void addDownDep(std::string dep)
    {
        _downDepList.push_back(dep);
    }
    
    int _data;
    std::string _name;
    std::list<std::string> _upDepList;
    std::list<std::string> _downDepList;
};

class Graph
{
public:
    Graph(std::string name)
    {
        this->_name = name;
    }
    
    std::string name()
    {
        return _name;
    }
    
    void addNode(Node* node)
    {
        _nodes.push_back(node);
    }
    
    // Helper method that performs a depth first search on the graph to give
    // us the topological ordering we want. Instead of maintaining a stack
    // of the nodes we see we simply place them inside the ordering array
    // in reverse order for simplicity.
    int dfs(int i, int srcIndex, std::vector<bool>& visited) {

      visited[srcIndex] = true;

      auto node = _nodes[srcIndex];
      if (node != nullptr)
      {
          for (auto& dep :node->_downDepList)
          {
              auto nodeIndex = getNode(dep);
              if (!visited[nodeIndex]) {
                  i = dfs(i, nodeIndex, visited);
              }
          }
      }

          _sortedNodes[i] = _nodes[srcIndex];
      return i - 1;
    }
    
    void doTopSort()
    {
        // graph knows number of nodes in the graph
        // graph knows about its graph
        _sortedNodes.reserve(_nodes.size());
        std::vector<bool> visited;
        visited.reserve(_nodes.size());
        for (int i=0; i<_nodes.size(); ++i)
        {
            visited.push_back(false);
            _sortedNodes.push_back(nullptr);
        }
        
        int index = _nodes.size() - 1;

        for (int srcIndex=0; srcIndex<_nodes.size(); ++srcIndex){
            if (!visited[srcIndex]){
                index = dfs(index, srcIndex, visited);
            }
        }

    }
        
    int getNode(std::string name){
        for (int i=0; i<_nodes.size(); ++i){
            if (_nodes[i]->_name == name){
                return i;
            }
        }
        
        return -1;
    }
        
    Node* getNodebyName(std::string name){
        for (int i=0; i<_nodes.size(); ++i){
            if (_nodes[i]->_name == name){
                return _nodes[i];
            }
        }
        
        return nullptr;
    }
    
    void displayGraphNodes(){
        std::cout << "Nodes: \n";
        for (auto& node:_nodes){
            std::cout << node->name() << " ";
        }
        std::cout << "\n";
    }
    
    void displayGraphSortedNodes(){
        std::cout << "Sorted Nodes: \n";
        for (auto& node:_sortedNodes){
            std::cout << node->name() << " ";
        }
        std::cout << "\n";
    }
        
    
    std::string _name;
    std::vector<Node*> _nodes;
    std::vector<Node*> _sortedNodes;
};

int main(){
//    n0 n1 n2 n3 n4 n5
//    Sorted Nodes:
//    n0 n5 n1 n2 n3 n4
    
    
    Graph graph("g1");
    
    Node node0("n0");
    graph.addNode(&node0);
    node0.addDownDep("n1");
    node0.addDownDep("n2");
    node0.addDownDep("n5");
    
    Node node1("n1");
    graph.addNode(&node1);
    node1.addDownDep("n3");
    node1.addDownDep("n2");
    node1.addUpDep("n0");
    // ----------------------------------
    
    Node node2("n2");
    graph.addNode(&node2);
    node2.addDownDep("n3");
    node2.addDownDep("n4");
    node2.addUpDep("n0");
    node2.addUpDep("n1");
    
    Node node3("n3");
    graph.addNode(&node3);
    node3.addDownDep("n4");
    node3.addUpDep("n1");
    node3.addUpDep("n2");
    
    Node node4("n4");
    graph.addNode(&node4);
    node4.addUpDep("n2");
    node4.addUpDep("n5");
    
    // -------------------------------------
    
    Node node5("n5");
    graph.addNode(&node5);
    node5.addDownDep("n4");
    node2.addUpDep("n0");
    
    
//    node5.addUpDep("n3");
//    node5.addUpDep("n4");
    
    // ----------------------- sort now ------
    
    graph.displayGraphNodes();
    graph.doTopSort();
    graph.displayGraphSortedNodes();
    
    return 0;
}
