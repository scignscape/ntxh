#pragma once
#define EPS 0.00001
#include <sstream>

template <typename T>
void MultiSetData<T>::require(T value, bool overwrite)
{
    std::string key = createKey(value);
    if (m_map.find(key) != m_map.end())
    {
        m_map[key]->quantity = overwrite ? 1 : m_map[key]->quantity + 1;
    }
    else
    {
        m_map[key] = std::make_shared<auxiliary::MultiSetItem<T>>(auxiliary::MultiSetItem<T>(value));
    }
}

template <typename T>
void MultiSetData<T>::require(T value, int quantity, bool overwrite)
{
    std::string key = createKey(value);

    if (m_map.find(key) != m_map.end())
    {
        m_map[key]->quantity = overwrite ? quantity : m_map[key]->quantity + quantity;
    }
    else
    {
        m_map[key] = std::make_shared<auxiliary::MultiSetItem<T>>(auxiliary::MultiSetItem<T>(value, quantity));
    }
}
template <typename T>
void MultiSetData<T>::checkUsedAll()
{
	typename std::map<std::string, std::shared_ptr<auxiliary::MultiSetItem<T>>>::iterator it = m_map.begin();
	it->first;
	while (it != m_map.end())
	{
		if(m_map[it->first]->quantity > 0)
		{
			FAIL() << "Value: " << it->first << " not used in required quantity.";
		}
		++it;
	}
	SUCCEED();
}


template <typename T>
void MultiSetData<T>::checkValue(T value)
{
    std::string key = createKey(value);

    if(m_map.find(key) != m_map.end())
    {
        if (m_map[key]->quantity-- == 0)
        {
            FAIL() << "Value: " << key << " used many times";
        }
        SUCCEED();
    }
    else
    {
        FAIL() << "Value: " << key << " was not found";
    }
}

template <typename T>
void MultiSetData<T>::reset()
{
    m_map.clear();
}

template<typename T>
std::string MultiSetData<T>::createKey(T value)
{
    std::stringstream strs;
    strs << std::fixed << std::setprecision(m_precision) << value;
    return strs.str();
}

template <typename T>
void MultiSetData<T>::setPrecision(int precision)
{
    m_precision = precision;
}
