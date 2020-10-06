#include <vector>
#include <string>
#include <chrono>
#include <ctime>
#include <unordered_set>

#include "traversal/GraphTraversal.h"
#include "structure/Graph.h"
#include "traversal/CPUGraphTraversal.h"
#include "structure/CPUGraph.h"
#include "util/C.h"

#define LABEL_V "basic_vertex"
#define LABEL_E "basic_edge"
#define NAME "name"

int main(int argc, char* argv[]) 
{
		CPUGraph graph;
		auto explanation = graph.traversal()->addV()->has("a", "b")->explain();
		printf("%s---\n", explanation.c_str());

		graph.traversal()->addV()->addV()->addV()->iterate();
		printf("Added 3 vertices to the graph.\n");
		graph.traversal()->V()->property("a", std::string("b"))->iterate();

  std::vector<Vertex*> vertices;

  std::list<Vertex*> sl = graph.vertices();

  std::for_each(sl.begin(), sl.end(), [&vertices](Vertex* v) {
   vertices.push_back(v);
  });

		VertexProperty<boost::any>* p = vertices.front()->property("a");
		std::cout << boost::any_cast<uint64_t>(vertices.front()->id()) << " Set property " << p->key() << " to " << boost::any_cast<std::string>(p->value()) << "\n";
		
		p = vertices[1]->property("a");
		std::cout << boost::any_cast<uint64_t>(vertices[1]->id()) << " Set property " << p->key() << " to " << boost::any_cast<std::string>(p->value()) << "\n";

		p = vertices[2]->property("a");
		std::cout << boost::any_cast<uint64_t>(vertices[2]->id()) << " Set property " << p->key() << " to " << boost::any_cast<std::string>(p->value()) << "\n";

		std::cout << "size: " << graph.vertices().size() << "\n";

//		graph.traversal()->V()->has("a", std::string("b"))->forEachRemaining([](boost::any& v){
//			Vertex* w = boost::any_cast<Vertex*>(v);
//			std::cout << "The Vertex with id " << boost::any_cast<uint64_t>(w->id()) << " has property a = b\n";
//		});

 return 0;
}


