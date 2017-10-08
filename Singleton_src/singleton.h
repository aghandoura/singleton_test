#pragma once
class singleton{
    public:
		static singleton* get_instance();
		static int get_instances_count() { return m_instances_count; }
		void kill();


    private:
		static int m_instances_count;
		singleton();
		~singleton();
        static singleton *m_instance;
		singleton& operator=(singleton& other) {};
};

