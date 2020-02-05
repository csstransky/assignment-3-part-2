#pragma once

#include <stdarg.h>
#include "string.h"
#include "object.h"

/**
 * An abstract Column that mainly stores parent functions for the children Columns.
 * 
 * IMPORTANT: There should NO constructed Column* classes, as this class is simply used as an 
 * abstract class. This means that casting is not necessary for IntColumn, FloatColumn, BoolColumn,
 * or StringColumn in order to properly use the functions of each.
 * Example:
 *      FloatColumn* fc = new FloatColumn();
 *      DataFrame* df = new DataFrame(df);
 *      Column* float_column = df->get_column(0);
 * 
 *      // superfluous check, but will return true
 *      if (float_column->is_float_column()) { 
 *          // No errors will be thrown, and even though float_column is a Column* type, 
 *          // it will use functions from its FloatColumn* subclass
 *          float_column->set(12.32);
 *      }
 */
class Column : public Object {
    public:
    /**
     * Returns the total number of elements inside the Column.
     * 
     * @return The total length of the Column
     */
    size_t size();

    /**
     * Gets a String from a StringColumn at a specified row.
     * 
     * NOTE: The default behavior of this function will be to throw an error. This function will
     * only work properly if called by a StringColumn.
     * 
     * @param row - The numbered row of the Column (starting at 0)
     * @return The String inside of the cell at the specified row
     */
    virtual String* get_string(size_t row);

    /**
     * Gets a Boolean from a BoolColumn at a specified row.
     * 
     * NOTE: The default behavior of this function will be to throw an error. This function will
     * only work properly if called by a BoolColumn.
     * 
     * @param row - The numbered row of the Column (starting at 0)
     * @return The Bool inside of the cell at the specified row
     */    
    virtual bool get_bool(size_t row);

    /**
     * Gets an int from a IntColumn at a specified row.
     * 
     * NOTE: The default behavior of this function will be to throw an error. This function will
     * only work properly if called by a IntColumn.
     * 
     * @param row - The numbered row of the Column (starting at 0)
     * @return The int inside of the cell at the specified row
     */
    virtual int get_int(size_t row);

    /**
     * Gets a float from a FloatColumn at a specified row.
     * 
     * NOTE: The default behavior of this function will be to throw an error. This function will
     * only work properly if called by a FloatColumn.
     * 
     * @param row - The numbered row of the Column (starting at 0)
     * @return The float inside of the cell at the specified row
     */
    virtual float get_float(size_t row);

    /**
     * Sets the bool value inside of a Column at a specified row.
     * 
     * NOTE: The default behavior of this function will be to throw an error. This function will
     * only work properly if called by a BoolColumn.
     * 
     * @param row - The numbered row of the Column (starting at 0)
     * @param bool_value - The Boolean value to be added to the cell of the Column
     */
    virtual void set(size_t row, bool bool_value);

    /**
     * Sets the int value inside of a Column at a specified row.
     * 
     * NOTE: The default behavior of this function will be to throw an error. This function will
     * only work properly if called by an IntColumn.
     * 
     * @param row - The numbered row of the Column (starting at 0)
     * @param int_value - The int value to be added to the cell of the Column
     */
    virtual void set(size_t row, int int_value);

    /**
     * Sets the float value inside of a Column at a specified row.
     * 
     * NOTE: The default behavior of this function will be to throw an error. This function will
     * only work properly if called by a FloatColumn.
     * 
     * @param row - The numbered row of the Column (starting at 0)
     * @param float_value - The float value to be added to the cell of the Column
     */
    virtual void set(size_t row, float float_value);

    /**
     * Sets the String value inside of a Column at a specified row.
     * 
     * NOTE: The default behavior of this function will be to throw an error. This function will
     * only work properly if called by a StringColumn.
     * 
     * @param row - The numbered row of the Column (starting at 0)
     * @param string_value - The String value to be added to the cell of the Column
     */
    virtual void set(size_t row, String* string_value);

    /**
     * Finds whether or not the Column is an IntColumn or not.
     * 
     * @return True if the Column class is an IntColumn, false otherwise.
     */
    virtual bool is_int_column();

    /**
     * Finds whether or not the Column is an FloatColumn or not.
     * 
     * @return True if the Column class is an FloatColumn, false otherwise.
     */
    virtual bool is_float_column();

    /**
     * Finds whether or not the Column is an BoolColumn or not.
     * 
     * @return True if the Column class is an BoolColumn, false otherwise.
     */
    virtual bool is_bool_column();

    /**
     * Finds whether or not the Column is an StringColumn or not.
     * 
     * @return True if the Column class is an StringColumn, false otherwise.
     */
    virtual bool is_string_column();

    /**
     * Gets the header for the Column.
     * 
     * @return A String representation of the header. If no header is present, a nullptr will be
     * returned.
     */
    String* get_header();
    
    /**
     * Replaces the String header for the Column with a new String header.
     * 
     * @param header - The String header to be set for the Column.
     */
    void set_header(String* header);

    /**
     * Adds a row to the Column with a default value in the cell.
     * 
     * CAUTION: This function should be used with great care when a Column is linked to a dataframe. 
     * Because a dataframe MUST have the same number of rows for EACH Column, make sure that this 
     * function applies to ALL Columns inside the dataframe.
     */
    virtual void add_row(); 
    // This being virtual or not is determined by how the arrays that store the data will be
    // implemented. This may not be virtual and instead be added separately to each Column instead.
    // Open an issue or pull request based off your implementation. 

    /**
     * Adds a row to the Column at a specified row with a default value in the cell.
     * 
     * NOTE: If the row index is out of bounds, then an "error" will be thrown.
     * 
     * CAUTION: This function should be used with great care when a Column is linked to a dataframe. 
     * Because a dataframe MUST have the same number of rows for EACH Column, make sure that this 
     * function applies to ALL Columns inside the dataframe.
     * 
     * @param row - The numbered row of the dataframe (starting from 0)
     */
    virtual void add_row(size_t row); 
    // This being virtual or not is determined by how the arrays that store the data will be
    // implemented. This may not be virtual and instead be added separately to each Column instead.
    // Open an issue or pull request based off your implementation. 

    /**
     * Removes a row from the Column at a specified row index.
     * 
     * NOTE: If the row index is out of bounds, then an "error" will be thrown.
     * 
     * CAUTION: This function should be used with great care when a Column is linked to a dataframe. 
     * Because a dataframe MUST have the same number of rows for EACH Column, make sure that this 
     * function applies to ALL Columns inside the dataframe.
     * 
     * @param row - The numbered row of the dataframe (starting from 0)
     */
    virtual void remove_row(size_t row);
    // This being virtual or not is determined by how the arrays that store the data will be
    // implemented. This may not be virtual and instead be added separately to each Column instead.
    // Open an issue or pull request based off your implementation. 
};


TODO ddo thi sthing
class IntColumn : public Column {
    public:
    /* Constructs an empty IntColumn with no header (nullptr) */
    IntColumn();

    /**
     * Constructs an IntColumn based off an amount of ints.
     * No header will be specified and be set to nullptr.
     * 
     * @param nums - An amount of integer numbers that will be added to the IntColumn
     */
    IntColumn(int nums, ...);

    /**
     * Constructs an IntColumn based off an amount of ints and a specific header.
     * 
     * @param nums - An amount of integer numbers that will be added to the IntColumn
     */
    IntColumn(String* header, int nums, ...);

    /* Deconstructs the IntColumn */
    ~IntColumn();

    /**
     * Determines if another object is equal to this one.
     * 
     * @return For an IntColumn to equal another IntColumn, all of their elements must be the same,
     * and the order of those elements must also be the same.
     */
    bool equals(Object* const obj);

    int get_int(size_t row);

    void set(size_t row, int int_value);

    bool is_string_column();
};

class FloatColumn : public Column {
    public:
    /* Constructs an empty FloatColumn with no header (nullptr) */
    FloatColumn();

    /**
     * Constructs a FloatColumn based off an amount of floats.
     * No header will be specified and be set to nullptr.
     * 
     * @param nums - An amount of float numbers that will be added to the FloatColumn
     */
    FloatColumn(float nums, ...);

    /**
     * Constructs a FloatColumn based off an amount of floats and a specific header.
     * 
     * @param nums - An amount of float numbers that will be added to the FloatColumn
     */
    FloatColumn(String* header, float nums, ...);

    /* Deconstructs the FloatColumn */
    ~FloatColumn();




    /**
     * Determines if another object is equal to this one.
     * 
     * @return For an FloatColumn to equal another FloatColumn, all of their elements must be the 
     * same, and the order of those elements must also be the same.
     */
    bool equals(Object* const obj);

    float get_float(size_t row);

    void set(size_t row, float float_value);

    bool is_float_column();
};

class BoolColumn : public Column {
    public:
    /* Constructs an empty BoolColumn with no header (nullptr) */
    BoolColumn();

    /**
     * Constructs a BoolColumn based off an amount of Bools.
     * No header will be specified and be set to nullptr.
     * 
     * @param nums - An amount of Bools that will be added to the BoolColumn
     */
    BoolColumn(bool bools, ...);

    /**
     * Constructs a BoolColumn based off an amount of Bools and a specific header.
     * 
     * @param nums - An amount of Bools that will be added to the BoolColumn
     */
    BoolColumn(String* header, bool bools, ...);

    /* Deconstructs the BoolColumn */
    ~BoolColumn();

    /**
     * Determines if another object is equal to this one.
     * 
     * @return For an BoolColumn to equal another BoolColumn, all of their elements must be the 
     * same, and the order of those elements must also be the same.
     */
    bool equals(Object* const obj);

    bool get_bool(size_t row);

    void set(size_t row, bool bool_value);

    bool is_bool_column();
};

class StringColumn : public Column {
    public:
    /* Constructs an empty StringColumn with no header (nullptr) */
    StringColumn();

    /**
     * Constructs a StringColumn based off an amount of Strings.
     * No header will be specified and be set to nullptr.
     * 
     * @param nums - An amount of Strings that will be added to the StringColumn
     */
    StringColumn(String* strings, ...);

    /**
     * Constructs a based off an amount of Strings and a specific header.
     * 
     * @param nums - An amount of Strings that will be added to the StringColumn
     */
    StringColumn(String* header, String* Strings, ...);

    /* Deconstructs the StringColumn */
    ~StringColumn();

    /**
     * Determines if another object is equal to this one.
     * 
     * @return For an StringColumn to equal another StringColumn, all of their elements must be the
     * same, and the order of those elements must also be the same.
     */
    bool equals(Object* const obj);

    String* get_string(size_t row);

    void set(size_t row, String* string_value);

    bool is_string_column();
};