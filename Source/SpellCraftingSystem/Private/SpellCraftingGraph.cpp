// Fill out your copyright notice in the Description page of Project Settings.


#include "SpellCraftingGraph.h"
#include "SpellCraftingNode.h"
#include "Containers/Array.h"
#include "Containers/Set.h"

void USpellCraftingGraph::TopologicalSort() {
	if (!this->ExecutionOrder.IsEmpty()) {
		return;
	}
	
	TSet<USpellCraftingNode*> Visited;
	TArray<USpellCraftingNode*> VisitedSubgraph;
	TArray<USpellCraftingNode*> Stack;
	for (USpellCraftingNode* Node : this->Nodes) {
		if (Visited.Contains(Node)) {
			continue;
		}

		Stack.Push(Node);
		while (!Stack.IsEmpty()) {
			USpellCraftingNode* Current = Stack.Pop();
			if (Visited.Contains(Current)) {
				continue;
			}
			
			Visited.Add(Current);
			VisitedSubgraph.Add(Current);
			for (USpellCraftingNode* Neighbor : Current->Predecessors()) {
				if (!Visited.Contains(Neighbor)) {
					Stack.Push(Neighbor);
				}
			}
		}

		while (!VisitedSubgraph.IsEmpty()) {
			this->ExecutionOrder.Add(VisitedSubgraph.Pop());
		}
	}
}

void USpellCraftingGraph::Execute() {
	this->TopologicalSort();
	for (USpellCraftingNode* Node : this->ExecutionOrder) {
		Node->Execute();
	}
}
