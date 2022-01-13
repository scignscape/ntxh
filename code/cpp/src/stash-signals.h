
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#ifndef STASH_SIGNALS__H
#define STASH_SIGNALS__H


#include "global-macros.h"

#include <QString>
#include <QPair>
#include <QSet>

#include <QObject>

#include <QAbstractButton>
#include <QPushButton>

template <typename> struct _signal_class;

template <typename OBJECT_Type, typename ...Args>
struct _signal_class<void (OBJECT_Type::*)(Args...)>
{
 typedef OBJECT_Type _type;
};


struct no_alt_base
{

};

template<typename OBJECT_Type>
struct _alt_base
{
 using _type = no_alt_base;
};

#define STASH_SIGNALS_ALT_BASE(x, y) \
template<> struct _alt_base<x> { \
 using _type = y; };


//template<>
//struct _alt_base<QPushButton>
//{
// using _type = QAbstractButton;
//};


template<typename OBJECT_Type>
struct _saved_mfn_connector
{
 //template<typename SIGNAL_Type>
 template<typename SIGNAL_OBJECT_Type, typename ...SIGNAL_Args>
 struct signal_type
 {
  typedef void (SIGNAL_OBJECT_Type::*SIGNAL_Type)(SIGNAL_Args...);
  typedef SIGNAL_Type (*get_signal_type)(QString, SIGNAL_Type);
  static SIGNAL_Type get_signal(QString fname, SIGNAL_Type add = nullptr)
  {
   static QMap<QString, SIGNAL_Type> static_map;
   SIGNAL_Type result = static_map.value(fname);
   if(add)
   {
    static_map[fname] = add;
   }
   return result;
  }

  //template<typename ALT_OBJECT_Type, typename ALT_SIGNAL_Type>
  static get_signal_type get_alt() //get_signal_type alt = nullptr)
  {
   static get_signal_type result = nullptr;
   if(!result)
   {
    //typedef QAbstractButton Alt_base;
    typedef typename _alt_base<OBJECT_Type>::_type Alt_base;
    result = (get_signal_type) &_saved_mfn_connector<Alt_base>::template signal_type<Alt_base, SIGNAL_Args...>::get_signal;;
   }
   return result;
   //typedef void (QAbstractButton::*alt_SIGNAL_Type)(SIGNAL_Args...);
   //return (get_signal_type) &_saved_mfn_connector<QAbstractButton>::signal_type<QAbstractButton, SIGNAL_Args...>::get_signal;
  }

 };
 OBJECT_Type* obj;

 template<typename SOBJECT_Type, typename ...Args>
 static void add_signal(QString name, void (SOBJECT_Type::*add)(Args...))
 {
  //typedef void (SOBJECT_Type::*ft)(Args...);
  // signal_type<void (OBJECT_Type::*)(Args...)>::get_signal(name, add);
  signal_type<OBJECT_Type, Args...>::get_signal(name, add);

 }

 //template<typename THIS_Type, typename FN_Type> //, typename ...ARGS>
 template<typename THIS_Type, typename ...Args>
 void resolve_connection(QString mfn, THIS_Type* _this, void(THIS_Type::*fn)(Args...) )
 {
 // auto _mfn = signal_type<void(OBJECT_Type::*)(Args...)>::get_signal(mfn);
  auto _mfn = signal_type<OBJECT_Type, Args...>::get_signal(mfn);


  //typename signal_type<bool>::pmfn _mfn
  //  = signal_type<bool>::get_pmfn(mfn);

  if(_mfn)
    obj->connect(obj, _mfn, _this, fn);

  else
  {
   auto alt = signal_type<OBJECT_Type, Args...>::get_alt();
   //auto alt = signal_type<void(OBJECT_Type::*)(Args...)>::get_alt();
   //auto _mfn1 = signal_type<void(OBJECT_Type::*)(Args...)>::get_alt()(mfn, nullptr);
   auto _mfn1 = alt(mfn, nullptr);
   if(_mfn1)
     obj->connect(obj, _mfn1, _this, fn);
  }


 }
};

//void signal_baseclass()

template<typename THIS_Type, typename ...Args> //, typename FN_Type>
struct _saved_mfn_connector_triple
{
 //typedef
 QString signal_name;
 THIS_Type* _this;
 //FN_Type fn;
 void(THIS_Type::*fn)(Args...);

 template<typename OBJECT_Type>
 friend void operator > (OBJECT_Type* lhs, const _saved_mfn_connector_triple& rhs)
 {
  _saved_mfn_connector<OBJECT_Type> smc{lhs};
  smc.resolve_connection//<THIS_Type, Args...>
    (rhs.signal_name, rhs._this, rhs.fn);
 }

};

struct _saved_mfn_connector_precursor
{
 QString signal_name;
 _saved_mfn_connector_precursor* operator->()
 {
  return this;
 }

 template<typename THIS_Type, typename ...Args> //, typename FN_Type>
 _saved_mfn_connector_triple<THIS_Type, Args...> _to_this(THIS_Type* _this,
   void (THIS_Type::*fn)(Args...))
 {
  return {signal_name, _this, fn};
 }

};


//template<typename OBJECT_Type>
//connector<OBJECT_Type>
//Cc(OBJECT_Type* obj) { return {obj}; }


template<typename MEMBER_Fn, typename THIS_Type, typename FN_Type>
struct _Connect_triple
{
 MEMBER_Fn _mfn;
 THIS_Type* _this;
 FN_Type _fn;

 _Connect_triple& operator--()
 {
  return *this;
 }

 _Connect_triple& operator-()
 {
  return *this;
 }

 _Connect_triple& operator!()
 {
  return *this;
 }

 template<typename OBJECT_Type>
 friend void operator- (OBJECT_Type* lhs,
   _Connect_triple<MEMBER_Fn, THIS_Type, FN_Type> triple)
 {
  lhs->connect(lhs, triple._mfn, triple._this, triple._fn);
 }

 template<typename OBJECT_Type>
 friend void operator/ (OBJECT_Type* lhs,
   _Connect_triple<MEMBER_Fn, THIS_Type, FN_Type> triple)
 {
  lhs->connect(lhs, triple._mfn, triple._this, triple._fn);
 }

 template<typename OBJECT_Type>
 friend void operator> (OBJECT_Type* lhs,
   _Connect_triple<MEMBER_Fn, THIS_Type, FN_Type> triple)
 {
  lhs->connect(lhs, triple._mfn, triple._this, triple._fn);
 }

 template<typename OBJECT_Type>
 friend void operator< (OBJECT_Type* lhs,
   _Connect_triple<MEMBER_Fn, THIS_Type, FN_Type> triple)
 {
  lhs->connect(lhs, triple._mfn, triple._this, triple._fn);
 }

 template<typename OBJECT_Type>
 friend void operator>> (OBJECT_Type* lhs,
   _Connect_triple<MEMBER_Fn, THIS_Type, FN_Type> triple)
 {
  lhs->connect(lhs, triple._mfn, triple._this, triple._fn);
 }

 template<typename OBJECT_Type>
 friend void operator| (OBJECT_Type* lhs,
   _Connect_triple<MEMBER_Fn, THIS_Type, FN_Type> triple)
 {
  lhs->connect(lhs, triple._mfn, triple._this, triple._fn);
 }

};

template<typename OBJECT_Type, typename MEMBER_Fn, typename THIS_Type, typename FN_Type>
struct _Connect_quad
{
 OBJECT_Type* _lhs;
 MEMBER_Fn _mfn;
 THIS_Type* _this;
 FN_Type _fn;

 void operator--()
 {
  _lhs->connect(_lhs, _mfn, _this, _fn);
 }
};

template<typename OBJECT_Type, typename MEMBER_Fn>
struct _Connect_precursor
{
 OBJECT_Type* _lhs;
 MEMBER_Fn _mfn;

 _Connect_precursor* operator ->()
 {
  return this;
 }

 template<typename THIS_Type, typename FN_Type>
 _Connect_quad<OBJECT_Type, MEMBER_Fn, THIS_Type, FN_Type> _to_this(THIS_Type* _this, FN_Type fn)
 {
  return {_lhs, _mfn, _this, fn};
 }

};

template<typename MEMBER_Fn>
struct _Connect
{
 MEMBER_Fn _mfn;

 _Connect* operator ->()
 {
  return this;
 }

 template<typename THIS_Type, typename FN_Type>
 _Connect_triple<MEMBER_Fn, THIS_Type, FN_Type> _to_this(THIS_Type* _this, FN_Type fn)
 {
  return {_mfn, _this, fn};
 }

};

#define to_this(x) \
  _to_this(this, &std::remove_reference<decltype(*this)>::type::x)

template<typename MEMBER_Fn>
_Connect<MEMBER_Fn> _Connect_(MEMBER_Fn mfn)
{
 return {mfn};
}

template<typename OBJECT_Type, typename MEMBER_Fn>
_Connect_precursor<OBJECT_Type, MEMBER_Fn> _pre_Connect_(OBJECT_Type* obj, MEMBER_Fn mfn)
{
 return {obj, mfn};
}


template<typename OBJECT_Type, typename SIGNAL_Type>
void _stash_signal(QString name, SIGNAL_Type signal)
{
 _saved_mfn_connector<OBJECT_Type>::add_signal(name, signal);

 //_saved_mfn_connector<_saved_mfn_connector_fiat_base>::add_signal(name, signal);

}

template<typename OBJECT_Type, typename SIGNAL_Type>
void _stash_signal(QString class_name, QString name, SIGNAL_Type signal)
{
 static QSet<QPair<QString, QString>> already_stashed;
 if(already_stashed.contains({class_name, name}))
   return;
 already_stashed.insert({class_name, name});

 _saved_mfn_connector<OBJECT_Type>::add_signal(name, signal);
}

template<typename OBJECT_Type, typename SIGNAL_Type>
void _stash_signal_strip_name(QString name, SIGNAL_Type signal)
{
 static QSet<QString> already_stashed;
 if(already_stashed.contains(name))
   return;
 already_stashed.insert(name);
 int i = name.lastIndexOf(':');
 if(i != -1)
 {
  name = name.mid(i + 1);
 }
 _stash_signal<OBJECT_Type, SIGNAL_Type>(name, signal);
}


#define stash_signal_1(x) \
  _stash_signal_strip_name<_signal_class<decltype(&x)>::_type, decltype(&x)>(#x, &x) \

#define stash_signal_2(x, y) \
  _stash_signal<x, decltype(&x::y)>(#x, #y, &x::y)

#define stash_signal(...) \
  _preproc_CONCAT(stash_signal_, _preproc_NUM_ARGS (__VA_ARGS__))(__VA_ARGS__)

#define _Connect_3(dummy1,_1,dummy2) _Connect_(_1)


#define _Connect_2(_1, _2) \
  _pre_Connect_(_1, &std::remove_reference<decltype(*_1)>::type::_2)



#define _Connect_1(_1) _saved_mfn_connector_precursor{#_1}

#define Connect(...) \
  _preproc_CONCAT(_Connect_, _preproc_NUM_ARGS (__VA_ARGS__))(__VA_ARGS__)


#endif // STASH_SIGNALS__H
