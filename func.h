#ifndef FUNC_HPP
#define FUNC_HPP

class Arr {

	private:
		const static size_t step = 10;
		size_t size;
		double *ptr;
		void change_size(size_t);

	public:
		Arr();
		Arr(size_t arraySize);
		inline ~Arr(){ delete[] ptr; }

		inline int 	get_size(){ return size; }
		void 	get_element();
		void 	get_array();
		void 	set_element();
		void 	set_array();
		void	delete_element();
		void	push_element();

};

#endif
