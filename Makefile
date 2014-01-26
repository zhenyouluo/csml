
bin_stack       = test_stack
bin_queue       = test_queue
bin_vector 		= test_vector
bin_pair 		= test_pair
bin_path		= bin
csml_path 		= -I includes/
rm 				= rm -rf

all:
	mkdir -p $(bin_path)
	$(CC) $(csml_path) tests/test_stack.c -o $(bin_path)/$(bin_stack)
	$(CC) $(csml_path) tests/test_queue.c -o $(bin_path)/$(bin_queue)    
	$(CC) $(csml_path) tests/test_vector.c -o $(bin_path)/$(bin_vector)    
	$(CC) $(csml_path) tests/test_pair.c -o $(bin_path)/$(bin_pair)    

clean:
	$(rm) $(bin_path)