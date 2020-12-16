#ifndef GRAPH_TRAVERSAL_H
#define GRAPH_TRAVERSAL_H

#include <stdlib.h>
#include <string.h>

#include <QString>

#include <QVector>

#include <QVector>
#include <list>
#include <functional>
#include <algorithm>
#include <iostream>

#include "structure/Direction.h"
#include "traversal/P.h"
#include "structure/Direction.h"
#include "traversal/Scope.h"

class Edge;
class Vertex;
class TraversalStep;
class Graph;
class GraphTraversalSource;
class Traverser;

class GraphTraversal
{
protected:
  QVector<TraversalStep*> steps;


private:
  GraphTraversalSource* source;

public:

  GraphTraversal();

	/*
		The given traversal source is allowed to be null, in the case of an
		anomymous traversal.
	*/
	GraphTraversal(GraphTraversalSource* src);
	GraphTraversal(GraphTraversal* trv);
	GraphTraversal(GraphTraversalSource* src, GraphTraversal* trv);

	Graph* getGraph();


	GraphTraversalSource* getTraversalSource();

 QVector<TraversalStep*>& getSteps()
 {
		return this->steps;
	}

 GraphTraversal* appendStep(TraversalStep* step)
 {
		this->steps.push_back(step);
		return this;
	}

 GraphTraversal* insertStep(size_t k, TraversalStep* step)
 {
		this->steps.insert(steps.begin() + k, step);
		return this;
	}

	// Steps
	GraphTraversal* addE(QString label);

	GraphTraversal* addV(QString label);

	GraphTraversal* addV();

	GraphTraversal* property(QString property_key, QVariant value);

	//GraphTraversal<auto n> aggregate(QString sideEffectLabel);
	//GraphTraversal<auto n> _and();
 //GraphTraversal<auto n> _and(QVector<GraphTraversal<auto m>> traversals);
	//GraphTraversal* as(QString sideEffectLabel);
	//GraphTraversal* barrier();
	//GraphTraversal* by(GraphTraversal* byTraversal);
	//GraphTraversal* by(QString label);
 //GraphTraversal* cap(QVector<QString> sideEffectLabels);
	//GraphTraversal<auto n> choose(GraphTraversal<A> ifTraversal, GraphTraversal<B> trueTraversal, GraphTraversal<C> falseTraversal);
	//GraphTraversal<auto n> choose(GraphTraversal<A> withOptionTraversal);
	
 GraphTraversal* coalesce(QVector<GraphTraversal*> traversals);
	//GraphTraversal* coin(float chance);
	//GraphTraversal constant(void* value, size_t size);
	GraphTraversal* count();
	//GraphTraversal* cyclicPath();
	//GraphTraversal* dedup();
	//GraphTraversal* drop();
	//GraphTraversal* emit();
	//GraphTraversal emit(Predicate predicate);
	//GraphTraversal* emit(GraphTraversal* emitTraversal);
	//GraphTraversal* fold();
	//GraphTraversal* from(GraphTraversal* fromTraversal);

	GraphTraversal* from(QString sideEffectLabel);

	GraphTraversal* from(Vertex* fromVertex);

	GraphTraversal* V();

	GraphTraversal* V(Vertex* vertex);

 GraphTraversal* V(QVector<Vertex*> vertices);

	//GraphTraversal* V(void* objects, size_t sizeOfEach, int length);
	//GraphTraversal group();
	//GraphTraversal group(QString sideEffectLabel);
	//GraphTraversal groupCount();
	//GraphTraversal groupCount(QString sideEffectLabel);
	//GraphTraversal has(QString key, void* value, size_t size); // dangerous operation
	//GraphTraversal has(QString label, QString key, void* value, size_t size); // dangerous operation

	template<typename T>
	GraphTraversal* has(QString key, std::function<bool(QVariant)> pred);

	template<typename T>
	GraphTraversal* has(QString key, T value);

	template<typename T>
	GraphTraversal* has(QString key);

	//GraphTraversal* has(QString key, GraphTraversal* valueTraversal);
	//GraphTraversal* has(QString key);
	//GraphTraversal* hasNot(QString key);
 //GraphTraversal* hasLabel(QVector<QString> labels);
	//GraphTraversal* hasLabel(QString label);
	//GraphTraversal* hasId(void* ids, size_t sizeOfEach, int length); // dangerous operation
	//GraphTraversal* hasValue(void* values, size_t* sizesOfEach, int length); // dangerous operation
	
	GraphTraversal* id();

	GraphTraversal* identity();
	//GraphTraversal inject(void* object, size_t size);
	//GraphTraversal* is(void* val, size_t size);
	//GraphTraversal is(Predicate predicate);
	//GraphTraversal key();
	//GraphTraversal* label();
	//GraphTraversal* limit(unsigned long theLimit);
	//GraphTraversal limit(Scope scope, unsigned long theLimit);
	//GraphTraversal* local(GraphTraversal* localTraversal);
	//GraphTraversal* loops();
 //GraphTraversal match(QVector<GraphTraversal> matchTraversals);
	//GraphTraversal* math(QString equation);
	//GraphTraversal* max();
	//GraphTraversal max(Scope scope);
	//GraphTraversal* mean();
	//GraphTraversal mean(Scope scope);
	
	GraphTraversal* min(std::function<int(Traverser*, Traverser*)> c);

	GraphTraversal* min();
	//GraphTraversal min(Scope scope);
	//GraphTraversal _not(GraphTraversal notTraversal);
	//GraphTraversal option(GraphTraversal optionTraversal);
	//GraphTraversal optional(GraphTraversal OptionalTraversal);
 //GraphTraversal _or(QVector<GraphTraversal> orTraversals);
	//GraphTraversal* order();
	//GraphTraversal order(Scope scope);
	// pagerank step not supported
	//GraphTraversal* path();
	// peerpressure step not supported
	//QString profile();
 //GraphTraversal project(QVector<QString> sideEffectLabels);
	// program step not supported
 //GraphTraversal properties(QVector<QString> labels);
	//GraphTraversal properties();
 //GraphTraversal propertyMap(QVector<QString> labels);
	//GraphTraversal propertyMap();
	//GraphTraversal range(long low, long high);
	//GraphTraversal repeat(GraphTraversal repeatTraversal);
	// sack step not supported
	//GraphTraversal* sample(int sampleSize);
	//GraphTraversal sample(Scope scope, int sampleSize);
	// single-label select is special
 GraphTraversal* select(QString sideEffectLabel)
 {
		//TODO write this
	}
 //GraphTraversal select(QVector<QString> sideEffectLabels);
	//GraphTraversal select(GraphTraversal selectTraversal);
	//GraphTraversal* simplePath();
	//GraphTraversal* skip(unsigned long toSkip);
	//GraphTraversal skip(Scope scope, unsigned long toSkip);
	//GraphTraversal* store(QString sideEffectLabel);
	//GraphTraversal subgraph(QString sideEffectLabel);
	//GraphTraversal* sum();
	//GraphTraversal sum(Scope scope);
	//GraphTraversal tail();
	//GraphTraversal tail(unsigned long theLimit);
	//GraphTraversal tail(Scope scope);
	//GraphTraversal tail(Scope scope, unsigned long theLimit);
	//GraphTraversal* timeLimit(long time);
 //GraphTraversal* to(Direction direction, QVector<QString> labels);
	//GraphTraversal* to(Direction direction);
	//GraphTraversal* to(Direction direction, QString label);
	//GraphTraversal* to(GraphTraversal* toTraversal); //MODULATOR for addE

	// MODULATOR for addE
	GraphTraversal* to(QString sideEffectLabel);

	// MODULATOR for addE
	GraphTraversal* to(Vertex* toVertex);

	//GraphTraversal* toV(Direction direction);
	//GraphTraversal tree(QString sideEffectLabel);
	//GraphTraversal tree();
	//GraphTraversal unfold();
 //GraphTraversal _union(QVector<GraphTraversal> unionTraversals);
	//GraphTraversal until(Predicate predicate);
	//GraphTraversal until(GraphTraversal untilTraversal);
	//GraphTraversal value();
	//GraphTraversal valueMap();
 //GraphTraversal valueMap(QVector<QString> labels);
	//GraphTraversal valueMap(bool includeIdLabelKeyValue);
 //GraphTraversal valueMap(bool includeIdLabelKeyValue, QVector<QString> labels);
	//GraphTraversal values();
 GraphTraversal* values(QVector<QString> labels);

	GraphTraversal* values(QString label);

	GraphTraversal* both();
 GraphTraversal* both(QVector<QString> labels);
	GraphTraversal* bothE();
 GraphTraversal* bothE(QVector<QString> labels);
	//GraphTraversal* bothV();
	//GraphTraversal* inV();
	//GraphTraversal* otherV();
	GraphTraversal* out();
 GraphTraversal* out(QVector<QString> labels);
	GraphTraversal* in();
 GraphTraversal* in(QVector<QString> labels);
	GraphTraversal* outE();
 GraphTraversal* outE(QVector<QString> labels);
	GraphTraversal* inE();
 GraphTraversal* inE(QVector<QString> labels);

	//GraphTraversal where(Predicate predicate);
	//GraphTraversal where(QString label, Predicate predicate);
	//GraphTraversal where(GraphTraversal<auto n> whereTraversal);

	// These may replace predicates...
	//GraphTraversal lt(double max_exclusive);
	//GraphTraversal gt(double min_exculsive);
	//GraphTraversal eq(double equal, double tolerance);
	//GraphTraversal eq(long equal);
	//GraphTraversal eq(int equal);
	//GraphTraversal eq(QString equal);
	//GraphTraversal

	void getInitialTraversal();

	// The explain finalizer which works in anonymous GraphTraversals
	QString explain();

	// Finalizing steps
	//boolean hasNext();

 QVector<QVariant> toVector()
 {
  QVector<QVariant> results;
		this->forEachRemaining([&](QVariant& a){results.push_back(a);});
		return results;
	}

 QList<QVariant> toList() {
  QList<QVariant> results;
		this->forEachRemaining([&](QVariant& a) {
			results.push_back(a);
		});
		return results;
	}

	QVariant next() { 
		return this->toVector()[0];
	}

	void forEachRemaining(std::function<void(QVariant&)> func);

	void iterate();

	//GraphTraversal toSet();
};

#ifndef __
#define __ (new GraphTraversal())
#endif

#include "structure/Graph.h"
#include "structure/Vertex.h"
#include "structure/Edge.h"

/*
	The "default" constructor.
*/
GraphTraversal::GraphTraversal()
{
 source = nullptr;
}

#include "traversal/GraphTraversalSource.h"

/*
	The given traversal source is allowed to be null, in the case of an
	anomymous traversal.
*/
GraphTraversal::GraphTraversal(GraphTraversalSource* src) : GraphTraversal()
{
	source = src;
}

#include "step/TraversalStep.h"
GraphTraversal::GraphTraversal(GraphTraversal* trv) : GraphTraversal()
{
	this->steps = trv->getSteps();
	this->source = trv->getTraversalSource();
}

GraphTraversal::GraphTraversal(GraphTraversalSource* src, GraphTraversal* trv)
{
	this->steps = trv->getSteps();
	this->source = src;
}

Graph* GraphTraversal::getGraph()
{
	return (*source).getGraph();
}


GraphTraversalSource* GraphTraversal::getTraversalSource()
{
	return source;
}

/*
	In general this should be called by the finalization steps in
	classes that extend GraphTraversal.
*/
void GraphTraversal::getInitialTraversal()
{
	// Apply each strategy to this traversal's traversers.
 std::for_each(this->source->getStrategies().begin(), this->source->getStrategies().end(), [this](TraversalStrategy strategy)
 {
		strategy(this->steps);
	});
}

#include "step/property/AddPropertyStep.h"
#include "step/vertex/VertexStep.h"
#include "step/graph/GraphStep.h"
#include "step/modulate/FromStep.h"
#include "step/modulate/ToStep.h"
#include "step/edge/AddEdgeStep.h"
#include "step/vertex/AddVertexStep.h"
#include "step/edge/AddEdgeStartStep.h"
#include "step/vertex/AddVertexStartStep.h"
#include "step/logic/CoalesceStep.h"
#include "step/IdStep.h"
#include "step/property/PropertyStep.h"
#include "step/logic/NoOpStep.h"
#include "step/logic/IdentityStep.h"
#include "step/property/HasStep.h"
#include "step/math/CountStep.h"
#include "step/math/MinStep.h"

GraphTraversal* GraphTraversal::addE(QString label){
	return this->appendStep(new AddEdgeStep(label));
}

GraphTraversal* GraphTraversal::addV(QString label) {
	return this->appendStep(new AddVertexStep(label));
}

GraphTraversal* GraphTraversal::addV() {
	return this->appendStep(new AddVertexStep());
}

GraphTraversal* GraphTraversal::coalesce(QVector<GraphTraversal*> traversals) {
	return this->appendStep(new CoalesceStep(traversals));
}

GraphTraversal* GraphTraversal::property(QString property_key, QVariant value) {
	return this->appendStep(new AddPropertyStep(property_key, value));
}

GraphTraversal* GraphTraversal::V() {
	return this->appendStep(new GraphStep(VERTEX, {}));
}

GraphTraversal* GraphTraversal::V(Vertex* vertex) {
	return this->appendStep(new GraphStep(VERTEX, {vertex->id()}));
}

GraphTraversal* GraphTraversal::V(QVector<Vertex*> vertices) {
 QVector<QVariant> ids;
	for(Vertex* v : vertices) ids.push_back(v->id());
	return this->appendStep(new GraphStep(VERTEX, ids));
}

GraphTraversal* GraphTraversal::from(QString sideEffectLabel) {
	// Because from() uses void* (sigh) this awkward memory copy is necessary.
	const char* base_string = sideEffectLabel.c_str();
	size_t size = (1 + strlen(base_string));

	char* sideEffectLabel_cpy = (char*)malloc(sizeof(char) * size);
	strncpy(sideEffectLabel_cpy, base_string, size);

	return this->appendStep(new FromStep(sideEffectLabel_cpy));
}

GraphTraversal* GraphTraversal::from(Vertex* fromVertex) {
	return this->appendStep(new FromStep(fromVertex));
}

// MODULATOR for addE
GraphTraversal* GraphTraversal::to(QString sideEffectLabel) {
	// Because to() uses void* (sigh) this awkward memory copy is necessary.
	const char* base_string = sideEffectLabel.c_str();
	size_t size = (1 + strlen(base_string));

	char* sideEffectLabel_cpy = (char*)malloc(sizeof(char) * size);
	strncpy(sideEffectLabel_cpy, base_string, size);

	return this->appendStep(new ToStep(sideEffectLabel_cpy));
}

// MODULATOR for addE
GraphTraversal* GraphTraversal::to(Vertex* toVertex) {
	return this->appendStep(new ToStep(toVertex));
}

GraphTraversal* GraphTraversal::both() {
	return this->appendStep(new VertexStep(BOTH, {}, VERTEX));
}

GraphTraversal* GraphTraversal::both(QVector<QString> labels) {
	return this->appendStep(new VertexStep(BOTH, labels, VERTEX));
}

GraphTraversal* GraphTraversal::bothE() {
	return this->appendStep(new VertexStep(BOTH, {}, EDGE));
}

GraphTraversal* GraphTraversal::bothE(QVector<QString> labels) {
	return this->appendStep(new VertexStep(BOTH, labels, EDGE));
}

//GraphTraversal* bothV();
//GraphTraversal* inV();
//GraphTraversal* otherV();

GraphTraversal* GraphTraversal::out() {
	return this->appendStep(new VertexStep(OUT, VERTEX));
}

GraphTraversal* GraphTraversal::out(QVector<QString> labels) {
	return this->appendStep(new VertexStep(OUT, labels, VERTEX));
}

GraphTraversal* GraphTraversal::in() {
	return this->appendStep(new VertexStep(IN, VERTEX));
}

GraphTraversal* GraphTraversal::in(QVector<QString> labels) {
	return this->appendStep(new VertexStep(IN, labels, VERTEX));
}

GraphTraversal* GraphTraversal::outE() {
	return this->appendStep(new VertexStep(OUT, EDGE));
}

GraphTraversal* GraphTraversal::outE(QVector<QString> labels) {
	return this->appendStep(new VertexStep(OUT, labels, EDGE));
}

GraphTraversal* GraphTraversal::inE() {
	return this->appendStep(new VertexStep(IN, EDGE));
}

GraphTraversal* GraphTraversal::inE(QVector<QString> labels) {
	return this->appendStep(new VertexStep(IN, labels, EDGE));
}

GraphTraversal* GraphTraversal::id() {
	return this->appendStep(new IdStep());
}

GraphTraversal* GraphTraversal::identity() {
	return this->appendStep(new IdentityStep());
}

GraphTraversal* GraphTraversal::min(std::function<int(Traverser*, Traverser*)> c) {
	return this->appendStep(new MinStep(c));
}

GraphTraversal* GraphTraversal::min() {
	return this->appendStep(new MinStep(nullptr));
}

GraphTraversal* GraphTraversal::count() {
	return this->appendStep(new CountStep());
}

template<typename T>
GraphTraversal* GraphTraversal::has(QString key, std::function<bool(QVariant)> pred) {
	return this->appendStep(new HasStep(key, pred));
}

template<typename T>
GraphTraversal* GraphTraversal::has(QString key, T value) {
	return this->appendStep(new HasStep(key, value, P<T>::eq(value)));
}

template<typename T>
GraphTraversal* GraphTraversal::has(QString key) {
	return this->appendStep(new HasStep(key, nullptr));
}

GraphTraversal* GraphTraversal::values(QVector<QString> labels) {
	return this->appendStep(new PropertyStep(VALUE, labels));
}

GraphTraversal* GraphTraversal::values(QString label) {
	return this->appendStep(new PropertyStep(VALUE, {label}));
}

QString GraphTraversal::explain() {
	this->getInitialTraversal();

	QString explanation = "GraphTraversal {\n";
	for(int k = 0; k < this->steps.size(); k++) explanation += this->steps[k]->getInfo() + "\n";

	return explanation + "}";
}

#include "traversal/Traverser.h"
#include <omp.h>

/*
void GraphTraversal::forEachRemaining(std::function<void(QVariant&)> func) {
	this->getInitialTraversal();
	
	TraverserSet traversers;
	std::for_each(this->steps.begin(), this->steps.end(), [&](TraversalStep* step){
		step->apply(this, traversers);
	});

	std::for_each(traversers.begin(), traversers.end(), [&](Traverser* trv){
		QVariant obj = trv->get();
		func(obj);
	});
}
*/


void GraphTraversal::forEachRemaining(std::function<void(QVariant&)> func) {
	this->getInitialTraversal();
	
	TraverserSet traversers;
	size_t current_step = 0;
	size_t num_steps = steps.size();
	
 while(current_step < num_steps)
 {
		steps[current_step++]->apply(this, traversers);
		TraverserSet new_traversers;

		size_t step = current_step;
		size_t k = 0;
		size_t sz = traversers.size();
		size_t thread;

  #pragma omp for private(step, k, thread)
  for(size_t k = 0; k < sz; ++k)
  {
			thread = 0; //? omp_get_thread_num();
			TraverserSet local_traversers(traversers.begin() + k, traversers.begin() + k + 1);
   while(step < num_steps && !steps[step]->is_barrier)
   {
				steps[step]->apply(this, local_traversers);
				step++;
				if(thread == 0) current_step = step;
			}

			#pragma omp critical 
			{
    new_traversers.append(local_traversers);  //insert(new_traversers.end(), local_traversers.begin(), local_traversers.end());
			}
		}

		traversers.swap(new_traversers);
		//TODO delete
	}

 std::for_each(traversers.begin(), traversers.end(), [&](Traverser* trv)
 {
		QVariant obj = trv->get();
		func(obj);
	});
}


void GraphTraversal::iterate()
{
	this->getInitialTraversal();

	TraverserSet traversers;
 std::for_each(this->steps.begin(), this->steps.end(), [&](TraversalStep* step)
 {
		step->apply(this, traversers);
	});
}

#endif
