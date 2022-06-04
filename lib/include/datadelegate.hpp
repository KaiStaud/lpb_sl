#include <string>
// A delegate to handle database transactions received by datarouter
// This thread runs the database:
void data_thread();

void init_storage();

/* Wrappers for accesssing database: */

void add_constellation(std::string data);

void get_constellation();