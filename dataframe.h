#pragma once

#include "string.h"
#include "object.h"
#include "column.h"
#include <stdarg.h>

/**
 * A dataframe is used for storing data tables. It is an ordered sequence of 
 * (optionally named) columns of equal length.
 * 
 * Spec here: http://janvitek.org/events/NEU/4500/s20/projects2.html
 */
class DataFrame : public Object {
    public:
    /* Creates an empty dataframe */
    DataFrame();

    /**
     * Creates a dataframe with columns.
     * 
     * NOTE: Any Columns that have less rows than the Column with the maximum amount of rows, will
     * have rows added to it (with default values) until that Column has an equal length of rows.
     * This is to ensure that all Columns in the DataFrame have EQUAL length.
     * NOTE: The default value for each Column will be specified in the respective Column comments.
     * 
     * @param columns - The premade columns to be added to the dataframe
     */
    DataFrame(Column* columns, ...);

    /**
     * Deconstructs the dataframe.
     */
    ~DataFrame();

    /**
     * Prints a representation of the dataframe into the console, with the header as the
     * first line, and then the subsequent rows of the dataframe.
     * 
     * Example:
     * 0 mpg cyl disp  hp drat   wt 
     * Mazda RX4     21.0   6  160 110 3.90 2.62
     * Mazda RX4 Wag 21.0   6  160 110 3.90 2.88
     * Datsun 710    22.8   4  108  93 3.85 2.32
     * 
     * NOTE: The example is simply a suggested output, and NOT the final representation of 
     * the print function.
     */
    void print();

    /**
     * Gets a String representation of a cell inside the dataframe.
     * 
     * NOTE: If the choosen column is NOT an StringColumn, or row and column are out of bounds, 
     * then an "error" should be thrown.
     * Suggestion of this "error" handling should be with an assert() function.
     * 
     * @param row - The numbered row of the dataframe (starting from 0)
     * @param column - The numbered column of the dataframe (starting from 0)
     * @return - A String* representation of the value inside of the cell
     */
    String* get_string(size_t row, size_t column);

    /**
     * Gets a Boolean representation of a cell inside the dataframe.
     * 
     * NOTE: If the choosen column is NOT an BoolColumn, or row and column are out of bounds, 
     * then an "error" should be thrown.
     * Suggestion of this "error" handling should be with an assert() function.
     * 
     * @param row - The numbered row of the dataframe (starting from 0)
     * @param column - The numbered column of the dataframe (starting from 0)
     * @return - A Boolean representation of the value inside of the cell
     */
    bool get_bool(size_t row, size_t column);

    /**
     * Gets an int representation of a cell inside the dataframe.
     * 
     * NOTE: If the choosen column is NOT an IntColumn, or row and column are out of bounds, 
     * then an "error" should be thrown.
     * Suggestion of this "error" handling should be with an assert() function.
     * 
     * @param row - The numbered row of the dataframe (starting from 0)
     * @param column - The numbered column of the dataframe (starting from 0)
     * @return - An int representation of the value inside of the cell
     */
    int get_int(size_t row, size_t column);

    /**
     * Gets a float representation of a cell inside the dataframe.
     * 
     * NOTE: If the choosen column is NOT an FloatColumn, or row and column are out of bounds, 
     * then an "error" should be thrown.
     * Suggestion of this "error" handling should be with an assert() function.
     * 
     * @param row - The numbered row of the dataframe (starting from 0)
     * @param column - The numbered column of the dataframe (starting from 0)
     * @return - A float representation of the value inside of the cell
     */
    float get_float(size_t row, size_t column);

    /**
     * Sets the value inside cell of the column of the dataframe.
     * 
     * NOTE: If the column of the bool_value is NOT a BoolColumn, or row and column are 
     * out of bounds, then an "error" should be thrown.
     * Suggestion of this "error" handling should be with an assert() function.
     * 
     * @param row - The numbered row of the dataframe (starting from 0)
     * @param column - The numbered column of the dataframe (starting from 0)
     * @param bool_value - The Boolean value that will replace the value inside of a BoolColumn
     */
    void set(size_t row, size_t column, bool bool_value);

    /**
     * Sets the value inside cell of the column of the dataframe.
     * 
     * NOTE: If the column of the int_value is NOT a IntColumn, or row and column are out of bounds,
     * then an "error" should be thrown.
     * Suggestion of this "error" handling should be with an assert() function.
     * 
     * @param row - The numbered row of the dataframe (starting from 0)
     * @param column - The numbered column of the dataframe (starting from 0)
     * @param int_value - The int value that will replace the value inside of a IntColumn
     */
    void set(size_t row, size_t column, int int_value);

    /**
     * Sets the value inside cell of the column of the dataframe.
     * 
     * NOTE: If the column of the float_value is NOT a FloatColumn, or row and column 
     * are out of bounds, then an "error" should be thrown.
     * Suggestion of this "error" handling should be with an assert() function.
     * 
     * @param row - The numbered row of the dataframe (starting from 0)
     * @param column - The numbered column of the dataframe (starting from 0)
     * @param float_value - The float value that will replace the value inside of a FloatColumn
     */
    void set(size_t row, size_t column, float float_value);

    /**
     * Sets the value inside cell of the column of the dataframe.
     * 
     * NOTE: If the column of the string_value is NOT a StringColumn, or row and column 
     * are out of bounds, then an "error" should be thrown.
     * Suggestion of this "error" handling should be with an assert() function.
     * 
     * @param row - The numbered row of the dataframe (starting from 0)
     * @param column - The numbered column of the dataframe (starting from 0)
     * @param string_value - The String value that will replace the value inside of a StringColumn
     */
    void set(size_t row, size_t column, String* string_value);

    /**
     * Checks to see if this column is a BoolColumn.
     * 
     * NOTE: If the column variable is out of bounds, an "error" will be thrown.
     * 
     * @param column - The numbered column of the dataframe (starting from 0)
     * @return True if the chosen column is a BoolColumn, false otherwise
     */
    bool is_bool_column(size_t column);

    /**
     * Checks to see if this column is an IntColumn.
     * 
     * NOTE: If the column variable is out of bounds, an "error" will be thrown.
     * 
     * @param column - The numbered column of the dataframe (starting from 0)
     * @return True if the chosen column is a IntColumn, false otherwise
     */
    bool is_int_column(size_t column);

    /**
     * Checks to see if this column is a FloatColumn.
     * 
     * NOTE: If the column variable is out of bounds, an "error" will be thrown.
     * 
     * @param column - The numbered column of the dataframe (starting from 0)
     * @return True if the chosen column is a FloatColumn, false otherwise
     */
    bool is_float_column(size_t column);

    /**
     * Checks to see if this column is a StringColumn.
     * 
     * NOTE: If the column variable is out of bounds, an "error" will be thrown.
     * 
     * @param column - The numbered column of the dataframe (starting from 0)
     * @return True if the chosen column is a StringColumn, false otherwise
     */
    bool is_string_column(size_t column);

    /**
     * Gets all the headers of the dataframe into an array of String*.
     * 
     * NOTE: If a column does not have a defined header, it will return a nullptr.
     * 
     * @return A String* array of all the headers for each column
     */
    String** get_headers();

    /**
     * Gets the header of a specified Column in String* format.
     * 
     * NOTE: If column is out of bounds, then an "error" will be thrown.
     * NOTE: If a column does not have a defined header, it will return a nullptr.
     * 
     * @param column - The numbered column of the dataframe (starting from 0)
     * @return A String* array of all the headers (or numbers) for each column
     */
    String* get_header(size_t column);

    /**
     * Sets the header for the specified Column with a new header.
     * 
     * NOTE: If column is out of bounds, then an "error" will be thrown.
     * 
     * @param column - The numbered column of the dataframe (starting from 0)
     * @param header - The header to be set for the Column
     */
    void set_header(size_t column, String* header);

    /**
     * Gets the Column from the dataframe.
     * 
     * @param index - The numbered column of the dataframe (starting from 0)
     * @return A Column from the dataframe
     */
    Column* get_column(size_t index);

    /**
     * Sets the Column for the dataframe.
     * 
     * NOTE: If the column being set has less rows than the number of rows in the dataframe, then
     * the Column will fill automatically fill in the rest of its rows with a default value.
     * 
     * @param index - The numbered column of the dataframe (starting from 0)
     * @param column - The Column to be set at index in the dataframe
     */
    void set_column(size_t index, Column* column);

    /**
     * Adds a Column to the dataframe to the "right" of the specified index.
     * 
     * NOTE: If the index is out of bounds, then an "error" will be thrown.
     * 
     * @param index - The numbered column of the dataframe (starting from 0)
     * @param column - The column to be added to the dataframe
     */
    void add_column(size_t index, Column* column);

    /**
     * Removes the specified Column from the dataframe.
     * 
     * NOTE: If column is out of bounds, then an "error" will be thrown.
     * 
     * @param row - The numbered row of the dataframe (starting from 0)
     */
    void remove_column(size_t column);

    /**
     * The number of data rows in the dataframe.
     * 
     * @return The number of rows in the dataframe.
     */
    size_t nrow();

    /**
     * The number of data columns in the dataframe.
     * 
     * @return The number of columns in the dataframe.
     */
    size_t ncol();

    /**
     * Adds an empty row to the dataframe with respective default empty values in the cells of each
     * Column.
     */
    void add_row();

    /**
     * Adds an empty row to the dataframe at the given row index with respective default 
     * empty values in the cells of each Column.
     * 
     * NOTE: If row is out of bounds, then an "error" will be thrown.
     * 
     * @param row - The numbered row of the dataframe (starting from 0)
     */
    void add_row(size_t row);

    /**
     * Removes the specified row from the dataframe, and its corresponding Columns.
     * 
     * NOTE: If row is out of bounds, then an "error" will be thrown.
     * 
     * @param row - The numbered row of the dataframe (starting from 0)
     */
    void remove_row(size_t row);


    /** This would be nice */
    DataFrame* get_row(size_t row);

    DataFrame* query(size_t col, String* string_name);
};