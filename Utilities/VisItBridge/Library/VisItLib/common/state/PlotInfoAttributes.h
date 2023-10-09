// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

#ifndef PLOTINFOATTRIBUTES_H
#define PLOTINFOATTRIBUTES_H
#include <state_exports.h>
#include <AttributeSubject.h>

#include <visitstream.h>

// ****************************************************************************
// Class: PlotInfoAttributes
//
// Purpose:
//    contains info set by the executed plot.
//
// Notes:      Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//
// ****************************************************************************

class STATE_API PlotInfoAttributes : public AttributeSubject
{
public:
    // These constructors are for objects of this class
    PlotInfoAttributes();
    PlotInfoAttributes(const PlotInfoAttributes &obj);
protected:
    // These constructors are for objects derived from this class
    PlotInfoAttributes(private_tmfs_t tmfs);
    PlotInfoAttributes(const PlotInfoAttributes &obj, private_tmfs_t tmfs);
public:
    virtual ~PlotInfoAttributes();

    virtual PlotInfoAttributes& operator = (const PlotInfoAttributes &obj);
    virtual bool operator == (const PlotInfoAttributes &obj) const;
    virtual bool operator != (const PlotInfoAttributes &obj) const;
private:
    void Init();
    void Copy(const PlotInfoAttributes &obj);
public:

    virtual const std::string TypeName() const;
    virtual bool CopyAttributes(const AttributeGroup *);
    virtual AttributeSubject *CreateCompatible(const std::string &) const;
    virtual AttributeSubject *NewInstance(bool) const;

    // Property selection methods
    virtual void SelectAll();
    void SelectData();

    // Property setting methods
    void SetData(const MapNode &data_);

    // Property getting methods
    const MapNode &GetData() const;
          MapNode &GetData();


    // Keyframing methods
    virtual std::string               GetFieldName(int index) const;
    virtual AttributeGroup::FieldType GetFieldType(int index) const;
    virtual std::string               GetFieldTypeName(int index) const;
    virtual bool                      FieldsEqual(int index, const AttributeGroup *rhs) const;

    // User-defined methods
    void PrintSelf(ostream &os);
    void Reset();
    void Merge(const PlotInfoAttributes &obj);

    // IDs that can be used to identify fields in case statements
    enum {
        ID_data = 0,
        ID__LAST
    };

private:
    MapNode data;

    // Static class format string for type map.
    static const char *TypeMapFormatString;
    static const private_tmfs_t TmfsStruct;
};
#define PLOTINFOATTRIBUTES_TMFS "m"

#endif