#!/usr/bin/env python3

# il faut 
#sudo apt-get update
#sudo apt-get install python3
#sudo apt-get install pip3
#pip3 install networkx
#pip3 install matplotlib
#pip3 install itermplot

import networkx as nx
import matplotlib.pyplot as plot

def main():
    def getEdge(line):
        data = line.split('-') #split string into a list
        G.add_edge(int(data[0]), int(data[1]))

    def init():
        filepath = '/tmp/lemin_result.txt'
        with open(filepath) as fp:
            line = fp.readline()
            while line:
                line = line.rstrip('\n')
                if line.find('-') >= 0 :
                    getEdge(line)
                line = fp.readline()

    def drawNetwork():
        cell = list(G.nodes)
        firstCell = cell.pop(0)
        lastCell = cell.pop(1)

        nx.draw_networkx_nodes(G, pos, cell, node_color='y')
        nx.draw_networkx_nodes(G, pos, nodelist=[firstCell], node_color='g')
        nx.draw_networkx_nodes(G, pos, nodelist=[lastCell], node_color='r')
        
    G = nx.Graph()
    init()
    pos=nx.spring_layout(G)
    drawNetwork()
    lines = list(G.edges)
    nx.draw_networkx_edges(G, pos, lines, edge_color='blue')
    nx.draw_networkx_labels(G, pos, font_size=13, font_color='k')
    plot.show()

if __name__ == "__main__":
    main();