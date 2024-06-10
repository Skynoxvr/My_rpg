#!/usr/bin/python3

import sys
import json

class Map:
    def __init__(self, width, height, twidth, theight):
        self.size = (width, height)
        self.tile_size = (twidth,theight)
        self.layers = list()

class Layer:
    def __init__(self, width, height, name, data):
        self.size = (width, height)
        self.data = data
        self.name = name

    def get_layer_data(self, f, map):
        for y in range(map.size[1]):
            for x in range(map.size[0]):
                if (self.data[y * map.size[0] + x] != 0):
                    f.write(str(x) + " " + str(y) + "\n")

def get_map():
    filename = sys.argv[1]
    j = json.load(open(filename, "r"))
    map = Map(j["width"], j["height"], j["tilewidth"], j["tileheight"])
    for l in j["layers"]:
        layer = Layer(l["width"], l["height"], l["name"], l["data"])
        map.layers.append(layer)
    return map

    
map = get_map()
f = open("res.coll", "w")
for layer in map.layers:
    print("Layer name: " + layer.name)
    if layer.name == "Collision":
        layer.get_layer_data(f, map)
f.close()
