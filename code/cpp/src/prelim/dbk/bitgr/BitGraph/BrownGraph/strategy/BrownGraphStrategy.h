#ifndef BROWNGRAPH_STRATEGY_H
#define BROWNGRAPH_STRATEGY_H

#include "strategy/TraversalStrategy.h"
#include "step/graph/GraphStep.h"
#include "step/vertex/VertexStep.h"
#include "step/IndexStep.h"
#include "step/HasWithIndexStep.h"

class BrownGraph;

void browngraph_strategy(BrownGraph* bg, QVector<TraversalStep*>& steps);

#include "structure/BrownGraph.h"
#include "step/BrownGraphStep.h"

void browngraph_strategy(BrownGraph* bg, QVector<TraversalStep*>& steps)
{
 if(steps[0]->uid() == GRAPH_STEP)
 {
		GraphStep* graph_step = static_cast<GraphStep*>(steps[0]);
  if(graph_step->getType() == EDGE)
  {
			steps[0] = new GraphStep(VERTEX, {});
   //?steps.emplace(steps.begin() + 1, new VertexStep(OUT, EDGE));

   steps[1] = new VertexStep(OUT, EDGE);
		}

		graph_step = static_cast<GraphStep*>(steps[0]);
  if(graph_step->getType() == VERTEX)
  {
   if(graph_step->get_element_ids().empty())
   {
    if(steps[1]->uid() == HAS_STEP)
    {
					HasStep* has_step = static_cast<HasStep*>(steps[1]);
     if(bg->is_indexed(has_step->get_key()))
     {
						IndexStep* index_list_step = new IndexStep(has_step->get_key(), has_step->get_value());
						delete steps[0];
						steps[0] = index_list_step;
						delete steps[1];
						steps.erase(steps.begin() + 1);
					}
     else
     {
      // //? added  ...
//      BrownGraphStep* browngraph_step = new BrownGraphStep(true, graph_step->getType(), graph_step->get_element_ids());
//      steps[0] = browngraph_step;
     }
				}
    else
    {
     BrownGraphStep* browngraph_step = new BrownGraphStep(true, graph_step->getType(), graph_step->get_element_ids());
     steps[0] = browngraph_step;
				}
			}
   else
   {
    BrownGraphStep* browngraph_step = new BrownGraphStep(true, graph_step->getType(), graph_step->get_element_ids());
    steps[0] = browngraph_step;
			}
		}
	}

 for(TraversalStep*& current_step : steps)//auto it = steps.begin() + 1; it != steps.end(); ++it)
 {
  //TraversalStep* current_step = *it;
  if(current_step->uid() == HAS_STEP)
  {
			HasStep* has_step = static_cast<HasStep*>(current_step);
   if(bg->is_indexed(has_step->get_key()))
   {
    //*it =
    current_step = new HasWithIndexStep(has_step->get_key(), has_step->get_value());
				delete current_step;
			}
  }
  else if(current_step->uid() == GRAPH_STEP)
  {
   GraphStep* graph_step = static_cast<GraphStep*>(current_step);
   BrownGraphStep* browngraph_step = new BrownGraphStep(true, //?false,
                                                        graph_step->getType(), graph_step->get_element_ids());
   //*it =
      //*it = browngraph_step;
   current_step = browngraph_step;
		}
	}
}

#endif
