/****************************************************************************
** Meta object code from reading C++ file 'SDL_Joysticks.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../../src/module/input/qjoysticks/src/QJoysticks/SDL_Joysticks.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SDL_Joysticks.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSSDL_JoysticksENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSSDL_JoysticksENDCLASS = QtMocHelpers::stringData(
    "SDL_Joysticks",
    "countChanged",
    "",
    "POVEvent",
    "QJoystickPOVEvent",
    "event",
    "axisEvent",
    "QJoystickAxisEvent",
    "buttonEvent",
    "QJoystickButtonEvent",
    "rumble",
    "QJoystickRumble",
    "request",
    "update",
    "configureJoystick",
    "const SDL_Event*"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSSDL_JoysticksENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x06,    1 /* Public */,
       3,    1,   57,    2, 0x06,    2 /* Public */,
       6,    1,   60,    2, 0x06,    4 /* Public */,
       8,    1,   63,    2, 0x06,    6 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      10,    1,   66,    2, 0x0a,    8 /* Public */,
      13,    0,   69,    2, 0x08,   10 /* Private */,
      14,    1,   70,    2, 0x08,   11 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 7,    5,
    QMetaType::Void, 0x80000000 | 9,    5,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15,    5,

       0        // eod
};

Q_CONSTINIT const QMetaObject SDL_Joysticks::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSSDL_JoysticksENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSSDL_JoysticksENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSSDL_JoysticksENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<SDL_Joysticks, std::true_type>,
        // method 'countChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'POVEvent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QJoystickPOVEvent &, std::false_type>,
        // method 'axisEvent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QJoystickAxisEvent &, std::false_type>,
        // method 'buttonEvent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QJoystickButtonEvent &, std::false_type>,
        // method 'rumble'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QJoystickRumble &, std::false_type>,
        // method 'update'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'configureJoystick'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const SDL_Event *, std::false_type>
    >,
    nullptr
} };

void SDL_Joysticks::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SDL_Joysticks *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->countChanged(); break;
        case 1: _t->POVEvent((*reinterpret_cast< std::add_pointer_t<QJoystickPOVEvent>>(_a[1]))); break;
        case 2: _t->axisEvent((*reinterpret_cast< std::add_pointer_t<QJoystickAxisEvent>>(_a[1]))); break;
        case 3: _t->buttonEvent((*reinterpret_cast< std::add_pointer_t<QJoystickButtonEvent>>(_a[1]))); break;
        case 4: _t->rumble((*reinterpret_cast< std::add_pointer_t<QJoystickRumble>>(_a[1]))); break;
        case 5: _t->update(); break;
        case 6: _t->configureJoystick((*reinterpret_cast< std::add_pointer_t<const SDL_Event*>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SDL_Joysticks::*)();
            if (_t _q_method = &SDL_Joysticks::countChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SDL_Joysticks::*)(const QJoystickPOVEvent & );
            if (_t _q_method = &SDL_Joysticks::POVEvent; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (SDL_Joysticks::*)(const QJoystickAxisEvent & );
            if (_t _q_method = &SDL_Joysticks::axisEvent; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (SDL_Joysticks::*)(const QJoystickButtonEvent & );
            if (_t _q_method = &SDL_Joysticks::buttonEvent; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject *SDL_Joysticks::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SDL_Joysticks::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSSDL_JoysticksENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SDL_Joysticks::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void SDL_Joysticks::countChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void SDL_Joysticks::POVEvent(const QJoystickPOVEvent & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SDL_Joysticks::axisEvent(const QJoystickAxisEvent & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void SDL_Joysticks::buttonEvent(const QJoystickButtonEvent & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
