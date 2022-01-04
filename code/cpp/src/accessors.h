
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#ifndef ACCESSORS__H
#define ACCESSORS__H

#include <functional>

#ifndef MACRO_PASTE
#define MACRO_PASTE(...) __VA_ARGS__
#endif


#ifndef ACCESSORS__DECLARATIVE__SET
#define ACCESSORS__DECLARATIVE__SET(cl, type, name) \
 cl& name(const type& _val) { name##_ = _val; return *this; }
#endif


#ifndef ACCESSORS__DECLARATIVE
#define ACCESSORS__DECLARATIVE(cl, type, name) \
ACCESSORS__DECLARATIVE__SET(cl, type, name) \
ACCESSORS__GET(type, name)
#endif


#ifndef ACCESSORS_get
#define ACCESSORS_get(type, name) \
 type name() const { return name##_; }
#endif

#ifndef ACCESSORS__GET
#define ACCESSORS__GET(type, name) \
 type name() const { return name##_; }
#endif

#ifndef ACCESSORS__IMPL_GET
#define ACCESSORS__IMPL_GET(type, name) \
 type name() const { return impl_.name(); }
#endif

#ifndef ACCESSORS__IMPL_SET
#define ACCESSORS__IMPL_SET(type, name) \
 void set_##name(type t) { impl_.set_##name(t); }
#endif


#ifndef ACCESSORS__IMPL
#define ACCESSORS__IMPL(type, name) \
 ACCESSORS__IMPL_GET(type, name) \
 ACCESSORS__IMPL_SET(type, name)
#endif


#ifndef RZ_CALL_IMPL
#define RZ_CALL_IMPL(type, name) \
 type name() const { return impl_.name(); }
#endif

#ifndef RZ_CALL_IMPL_VOID
#define RZ_CALL_IMPL_VOID(type, name) \
 void name(type arg) { impl_.name(arg); }
#endif


#ifndef ACCESSORS__CGET
#define ACCESSORS__CGET(type, name) \
 const type name() const { return name##_; }
#endif


#ifndef ACCESSORS__STATIC_GET
#define ACCESSORS__STATIC_GET(type, name) \
 static type name() { return name##_; }
#endif


#ifndef ACCESSORS__RGET
#define ACCESSORS__RGET(type, name) \
 type& name() { return name##_; }
#endif

#ifndef ACCESSORS_rget
#define ACCESSORS_rget(type, name) \
 type& name() { return name##_; }
#endif

#ifndef ACCESSORS__RGET_CONST
#define ACCESSORS__RGET_CONST(type, name) \
 type& name() const { return (type&) name##_; }
#endif

#ifndef ACCESSORS_rget_const
#define ACCESSORS_rget_const(type, name) \
 type& name() const { return (type&) name##_; }
#endif

#ifndef ACCESSORS__CONST_RGET
#define ACCESSORS__CONST_RGET(type, name) \
 const type& name() const { return name##_; }
#endif

#ifndef ACCESSORS_const_rget
#define ACCESSORS_const_rget(type, name) \
 const type& name() const { return name##_; }
#endif

#ifndef ACCESSORS__CONST_RGET_NONCONST
#define ACCESSORS__CONST_RGET_NONCONST(type, name) \
 const type& name() { return name##_; }
#endif

#ifndef ACCESSORS__NONCONST_RGET_CONST
#define ACCESSORS__NONCONST_RGET_CONST(type, name) \
 type& name() const { return (type&) name##_; }
#endif

#ifndef ACCESSORS__RGET_DEREF
#define ACCESSORS__RGET_DEREF(type, name) \
 type& name() { return *name##_; }
#endif


#ifndef ACCESSORS__STATIC_RGET
#define ACCESSORS__STATIC_RGET(type, name) \
 static type& name() { return name##_; }
#endif


#ifndef ACCESSORS__SET
#define ACCESSORS__SET(type, name) \
 void set_##name(type _arg_) { name##_ = _arg_; }
#endif

#ifndef ACCESSORS_set
#define ACCESSORS_set(type, name) \
 void set_##name(type _arg_) { name##_ = _arg_; }
#endif


#ifndef ACCESSORS__SETR
#define ACCESSORS__SETR(type, name) \
 auto& set_##name(type _arg_) { name##_ = _arg_; return *this; }
#endif

#ifndef ACCESSORS_setr
#define ACCESSORS_setr(type, name) \
 auto& set_##name(type _arg_) { name##_ = _arg_; return *this; }
#endif


#ifndef ACCESSORS__SETP
#define ACCESSORS__SETP(type, name) \
 auto set_##name(type _arg_) { name##_ = _arg_; return this; }
#endif


#ifndef ACCESSORS_setp
#define ACCESSORS_setp(type, name) \
 auto set_##name(type _arg_) { name##_ = _arg_; return this; }
#endif


#ifndef Q_INVOKABLE__ACCESSORS__SET
#define Q_INVOKABLE__ACCESSORS__SET(type, name) \
 void Q_INVOKABLE set_##name(type _arg_) { name##_ = _arg_; }
#endif


#ifndef ACCESSORS__SDECLARE
#define ACCESSORS__SDECLARE(type, name) \
 void set_##name(type name);
#endif

#ifndef ACCESSORS__SET__IMPL
#define ACCESSORS__SET__IMPL(type, name) \
 void set_##name(type name)
#endif


#ifndef ACCESSORS__GDECLARE
#define ACCESSORS__GDECLARE(type, name) \
 type name() const;
#endif


#ifndef ACCESSORS__DECLARE
#define ACCESSORS__DECLARE(type, name) \
 ACCESSORS__GDECLARE(type, name) \
 ACCESSORS__SDECLARE(type, name)
#endif


#ifndef ACCESSORS__GSDECLARE
#define ACCESSORS__GSDECLARE(type, name) \
 type get_##name() const; \
 ACCESSORS__SDECLARE(type, name)
#endif


#ifndef ACCESSORS
#define ACCESSORS(type, name) \
 ACCESSORS_get(MACRO_PASTE(type), name) \
 ACCESSORS_set(MACRO_PASTE(type), name)
#endif


#ifndef ACCESSORSR
#define ACCESSORSR(type, name) \
 ACCESSORS__GET(MACRO_PASTE(type), name) \
 ACCESSORS__SETR(MACRO_PASTE(type), name)
#endif


#ifndef ACCESSORSP
#define ACCESSORSP(type, name) \
 ACCESSORS__GET(MACRO_PASTE(type), name) \
 ACCESSORS__SETP(MACRO_PASTE(type), name)
#endif


// // this all implements the set_fn() << ... syntax
template<typename OBJECT_Type, typename FN_Type>
struct fn_setter
{
 OBJECT_Type& _this;
 void(*setter)(OBJECT_Type&, FN_Type);
 void operator << (FN_Type fn)
 {
  setter(_this, fn);
 }
};


#ifndef FN_VIA_OP
#define FN_VIA_OP(typ ,x) \
  set_##x##_{*this, &typ::static_set_##x}
#endif


#ifndef ACCESSORS_FN_SETTER_VIA_OP_DECLARE
#define ACCESSORS_FN_SETTER_VIA_OP_DECLARE(typ, ret_args, fname) \
 private: static void static_set_##fname(typ& _this, std::function<ret_args> fn) \
 { \
  _this.set_##fname(fn); \
 } \
 fn_setter<typ, std::function<ret_args>> set_##fname##_; public:
#endif


#ifndef ACCESSORS_FN_SET
#define ACCESSORS_FN_SET(ret_args ,x) \
  ACCESSORS__SET(std::function<ret_args> ,x)
#endif



#ifndef ACCESSORS_FN_SET_VIA_OP
#define ACCESSORS_FN_SET_VIA_OP(typ, ret_args ,x) \
 ACCESSORS_FN_SET(ret_args ,x) \
 ACCESSORS_FN_SETTER_VIA_OP_DECLARE(typ, ret_args ,x) \
 fn_setter<typ, std::function<ret_args>> set_##x() { return set_##x##_; }
#endif



#ifndef ACCESSORS_FN_VIA_OP
#define ACCESSORS_FN_VIA_OP(typ, ret_args ,x) \
  ACCESSORS__GET(std::function<ret_args> ,x) \
  ACCESSORS_FN_SET_VIA_OP(typ, ret_args ,x)
#endif



#ifndef Q_INVOKABLE__ACCESSORS
#define Q_INVOKABLE__ACCESSORS(type, name) \
 ACCESSORS__GET(type, name) \
 Q_INVOKABLE__ACCESSORS__SET(type, name)
#endif


#ifndef ACCESSORS__SET__CONST
#define ACCESSORS__SET__CONST(type, name) \
 void set_##name(type _arg_) const { name##_ = _arg_; }
#endif

#ifndef ACCESSORS__CONST
#define ACCESSORS__CONST(type, name) \
 ACCESSORS__GET(type, name) \
 ACCESSORS__SET__CONST(type, name)
#endif


#ifndef ACCESSORS__DO
#define ACCESSORS__DO(type, name) \
 void name##__do(std::function<void(type)> fn) const { fn(name()); }
#endif


#ifndef ACCESSORS__GDECLARE__DO
#define ACCESSORS__GDECLARE__DO(type, name) \
  ACCESSORS__GDECLARE(type, name) \
  ACCESSORS__DO(type, name)
#endif


#ifndef ACCESSORS__DECLARE__DO
#define ACCESSORS__DECLARE__DO(type, name) \
  ACCESSORS__DECLARE(type, name) \
  ACCESSORS__DO(type, name)
#endif


#endif //ACCESSORS__H
