#pragma once
#include <cstddef>
#include <algorithm>

#define __IT_OUTOFRANGE     "Iterátor túlindexelés!"
#define __VEC_OUTOFRANGE    "Vector túlindexelés!"
#define __VEC_EMPTY         "Üres Vectornak nem lehet kikérni elemét!"

template<typename T>
class Vector {
    private:
        T* _arr;        ///< Dinamikusan lefoglalt tömb az adatok tárolására.
        size_t _cap;    ///< Jelenlegi tárolókapacitás.
        size_t _size;   ///< Jelenleg eltárolt elemek száma.
    public:
        Vector(size_t size = 0) : _arr(new T[size]), _cap(size), _size(0) {}
        virtual ~Vector() { delete[] _arr; }


        /**
         * A jelenleg eltárolt elemek száma.
         * 
         * \returns Az elemek száma.
         */
        size_t size() const { return _size; }


        /**
         * A tárolt adatok kiürítése.
         * 
         * \remarks
         * A méret nullázódik, a kapacitás megmarad!
         */
        void clear() { _size = 0; }


        /**
         * A tárolókapacitás átméretezése.
         * 
         * \param size Az új méret.
         * 
         * \remarks
         * Méretcsökkenés esetén törlődnek a "kilógó" adatok.
         */
        void resize(size_t size) {
            if(size == _cap)
                return;

            _cap = size;
            T* temp = new T[_cap];
            _size = std::min(_size, _cap);
            for(size_t i = 0; i < _size; i++)
            {
                temp[i] = _arr[i];
            }
            delete[] _arr;
            _arr = temp;
        }

        /**
         * Pointer az első elemre.
         * 
         * \returns Pointer az eltárolt adatok elejére.
         * 
         * \remarks
         * Iterátoros működés helyettesítésére.
         */
        T* begin() const { return _arr; }


        /**
         * Pointer az utolsó elem utánra.
         * 
         * \returns Pointer az eltárolt adatok végére. (NEM a kapacitás végére!)
         * 
         * \remarks
         * Iterátoros működés helyettesítésére.
         */
        T* end() const { return _arr+_size; }


        /**
         * Új adat beszúrása a Vectorba.
         * 
         * \param n Az új elem.
         * 
         * \remarks
         * Automatikusan növeli a kapacitást, ha betelne.
         */
        void push_back(const T& n) {
            if(_size == _cap)
                resize(std::max(_cap*2, (size_t)2));

            _arr[_size++] = n;
        }
        

        /**
         * Elem törlése a Vectorból.
         * 
         * \param index A törlésre szánt elem indexe.
         * 
         * \throws std::out_of_range Ha az index kilóg az eltárolt elemek határán.
         */
        void erase(size_t index) {
            if(index >= _size)
                throw std::out_of_range(__VEC_OUTOFRANGE);
            
            _size--;
            for(size_t i = index; i < _size; i++)
            {
                _arr[i] = _arr[i+1];
            }
        }


        /**
         * Visszaadja az utolsó eltárolt elemet.
         * 
         * \returns Az utolsó elem.
         * 
         * \throws std::out_of_range Ha nincs egyetlen eltárolt elem sem.
         */
        T& back() const {
            if(_size == 0)
                throw std::out_of_range(__VEC_EMPTY);
            
            return _arr[_size-1];
        }


        /**
         * Indexelő operátor az adatok kikérésére.
         * 
         * \param index A keresett elem indexe.
         * 
         * \returns A keresett elem.
         * 
         * \throws std::out_of_range Ha a keresett index kilóg az eltárolt elemek határán.
         */
        T& operator[](size_t index) const {
            if(index >= _size)
                throw std::out_of_range(__VEC_OUTOFRANGE);

            return _arr[index];
        }
};

#undef __IT_OUTOFRANGE
#undef __VEC_OUTOFRANGE
#undef __VEC_EMPTY