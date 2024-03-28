import numpy as np
from LL import LL

class GraphNode:
    def __init__(self, value):
        self.value = value
        self.neighbours = LL()

def make_graph():
    yyz = GraphNode("YYZ")
    yvr = GraphNode("YVR")
    yul = GraphNode("YUL")
    whitehorse = GraphNode("Whitehorse")
    yyz.neighbours.insert(0, yvr)
    yyz.neighbours.insert(0, yul)
    yvr.neighbours.insert(0, yyz)
    yvr.neighbours.insert(0, yul)
    yvr.neighbours.insert(0, whitehorse)
    yul.neighbours.insert(0, yyz)
    yul.neighbours.insert(0, yvr)
    whitehorse.neighbours.insert(0,yvr)
    
    airport_LL = LL()
    for airport in [yyz, yvr, yul, whitehorse]:
        airport_LL.insert(0, airport)
    return airport_LL

def are_linked(node1, node2):
    current = node1.neighbours.head
    while current is not None:
        if current.data == node2:
            return True
        current = current.next
    return False

def node_from_string(nodes, node_str):
    current = nodes.head
    while current is not None:
        if current.data.value == node_str:
            return current.data
        current = current.next
    return None

def are_linked_string(nodes, node1_str, node2_str):
    node1 = node_from_string(nodes, node1_str)
    node2 = node_from_string(nodes, node2_str)
    if node1 is None or node2 is None:
        return False
    return are_linked(node1, node2)

if __name__ == '__main__':
    airports = make_graph()
    print("Toronto (YYZ) is connected to Montreal (YUL)?", are_linked_string(airports, "YYZ", "YUL"))