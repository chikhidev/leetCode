"""
{1: [2]}
 |-> 1, budget: 4, present price: 3, profit: 5 - 3 = 2
[2]
"""
import math

class Solution:
    tree = {}
    future = []
    present = []

    def calc_tree_profit(self, present_price:int, curr_node:int, budget:int, local_profits:List[int], depth=0):
        if present_price > budget:
            return

        # print(depth * '\t', '|->',  curr_node, end=', ')
        # print(f"budget: {budget}", end=', ')
        # print(f"present price: {present_price}", end=', ')

        profit = (self.future[curr_node - 1] - present_price)
        # print(f"profit: {self.future[curr_node - 1]} - {present_price} = {profit}")

        if len(local_profits) == 0 or (len(local_profits) - 1) < depth:
            local_profits.append(profit)
        elif local_profits[depth] < profit:
            local_profits[depth] = profit

        existing_node = self.tree.get(curr_node)
        if existing_node is None:
            return
        for node in existing_node:
            node_present_price = math.floor(self.present[node - 1] / 2)
            self.calc_tree_profit(node_present_price, node, budget - present_price, local_profits, depth + 1)


    def maxProfit(self, n: int, present: List[int], future: List[int], hierarchy: List[List[int]], budget: int) -> int:
        self.tree = {}
        self.future = future
        self.present = present
        profits = []

        if n == 0: return 0
        if n == 1:
            profit = future[0] - present[0]
            return profit if profit >= 0 else 0

        for pair in hierarchy:
            if self.tree.get(pair[0]) is None:
                self.tree[pair[0]] = [pair[1]]
            else:
               self.tree[pair[0]].append(pair[1])
            
            if self.tree.get(pair[1]) is None:
                self.tree[pair[1]] = []

        for node, subs in self.tree.items():
            local_profits = []
            self.calc_tree_profit(self.present[node - 1], node, budget, local_profits)
            profits.append(sum(local_profits))

        # print(profits)

        return max(profits) if len(profits) > 0 else 0
 
