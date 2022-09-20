
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#ifndef PHR_MINIMAL_EVALUATOR__H
#define PHR_MINIMAL_EVALUATOR__H

#include <QMap>

#include "accessors.h"

#include "phr-channel-group-evaluator.h"
#include "phaon-ir/phr-result-holder.h"

#include "kans.h"

KANS_(Phaon)


class PHR_Channel_Group;

class PHR_Minimal_Evaluator : public PHR_Channel_Group_Evaluator
{
 PHR_Result_Holder rh_;

public:

 enum class Kernal_Operators {
   N_A, Add, Subtract, Less_Than, Equal, Bool
 };

private:

 Kernal_Operators kernel_operator_;

public:

 PHR_Minimal_Evaluator(PhaonIR& phr, PHR_Channel_Group& channel_group);

 ACCESSORS(Kernal_Operators ,kernel_operator)

 static Kernal_Operators parse_kernel_operator(QString fn);

 void run_eval() Q_DECL_OVERRIDE;
 void run_eval(QVector<qint32>& args);

 void* get_result_value() Q_DECL_OVERRIDE;
 QString get_result_string() Q_DECL_OVERRIDE;

 void debug_report() Q_DECL_OVERRIDE;

};

_KANS(Phaon)

#endif // PHR_MINIMAL_EVALUATOR__H
