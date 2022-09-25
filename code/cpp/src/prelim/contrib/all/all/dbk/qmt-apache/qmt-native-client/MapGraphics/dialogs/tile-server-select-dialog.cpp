


/*
The code is licensed under the MIT License <http://opensource.org/licenses/MIT>:

Copyright (c) 2015-2017 Niels Lohmann.

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
of the Software, and to permit persons to whom the Software is furnished to do
so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef NLOHMANN_FIFO_MAP_HPP
#define NLOHMANN_FIFO_MAP_HPP

#include <algorithm>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <unordered_map>
#include <utility>
#include <vector>

/*!
@brief namespace for Niels Lohmann
@see https://github.com/nlohmann
*/
namespace nlohmann
{

template<class Key>
class fifo_map_compare
{
  public:
    /// constructor given a pointer to a key storage
    fifo_map_compare(
        std::unordered_map<Key, std::size_t>* keys,
        std::size_t timestamp = 1)
        :
        m_timestamp(timestamp),
        m_keys(keys)
    {}

    /*!
    This function compares two keys with respect to the order in which they
    were added to the container. For this, the mapping keys is used.
    */
    bool operator()(const Key& lhs, const Key& rhs) const
    {
        // look up timestamps for both keys
        const auto timestamp_lhs = m_keys->find(lhs);
        const auto timestamp_rhs = m_keys->find(rhs);

        if (timestamp_lhs == m_keys->end())
        {
            // timestamp for lhs not found - cannot be smaller than for rhs
            return false;
        }

        if (timestamp_rhs == m_keys->end())
        {
            // timestamp for rhs not found - timestamp for lhs is smaller
            return true;
        }

        // compare timestamps
        return timestamp_lhs->second < timestamp_rhs->second;
    }

    void add_key(const Key& key)
    {
        m_keys->insert({key, m_timestamp++});
    }

    void remove_key(const Key& key)
    {
        m_keys->erase(key);
    }

  private:
    /// helper to access m_timestamp from fifo_map copy ctor,
    /// must have same number of template args as fifo_map
    template <
        class MapKey,
        class MapT,
        class MapCompare,
        class MapAllocator
        > friend class fifo_map;

  private:
    /// the next valid insertion timestamp
    std::size_t m_timestamp = 1;

    /// pointer to a mapping from keys to insertion timestamps
    std::unordered_map<Key, std::size_t>* m_keys = nullptr;
};


template <
    class Key,
    class T,
    class Compare = fifo_map_compare<Key>,
    class Allocator = std::allocator<std::pair<const Key, T>>
    > class fifo_map
{
  public:
    using key_type = Key;
    using mapped_type = T;
    using value_type = std::pair<const Key, T>;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;
    using key_compare = Compare;
    using allocator_type = Allocator;
    using reference = value_type&;
    using const_reference = const value_type&;
    using pointer = typename std::allocator_traits<Allocator>::pointer;
    using const_pointer = typename std::allocator_traits<Allocator>::const_pointer;

    using internal_map_type = std::map<Key, T, Compare, Allocator>;

    using iterator = typename internal_map_type::iterator;
    using const_iterator = typename internal_map_type::const_iterator;
    using reverse_iterator = typename internal_map_type::reverse_iterator;
    using const_reverse_iterator = typename internal_map_type::const_reverse_iterator;

  public:
    /// default constructor
    fifo_map() : m_keys(), m_compare(&m_keys), m_map(m_compare) {}

    /// copy constructor
    fifo_map(const fifo_map &f) : m_keys(f.m_keys), m_compare(&m_keys, f.m_compare.m_timestamp), m_map(f.m_map.begin(), f.m_map.end(), m_compare) {}

    /// constructor for a range of elements
    template<class InputIterator>
    fifo_map(InputIterator first, InputIterator last)
        : m_keys(), m_compare(&m_keys), m_map(m_compare)
    {
        for (auto it = first; it != last; ++it)
        {
            insert(*it);
        }
    }

    /// constructor for a list of elements
    fifo_map(std::initializer_list<value_type> init) : fifo_map()
    {
        for (auto x : init)
        {
            insert(x);
        }
    }


    /*
     * Element access
     */

    /// access specified element with bounds checking
    T& at(const Key& key)
    {
        return m_map.at(key);
    }

    /// access specified element with bounds checking
    const T& at(const Key& key) const
    {
        return m_map.at(key);
    }

    /// access specified element
    T& operator[](const Key& key)
    {
        m_compare.add_key(key);
        return m_map[key];
    }

    /// access specified element
    T& operator[](Key&& key)
    {
        m_compare.add_key(key);
        return m_map[key];
    }


    /*
     * Iterators
     */

    /// returns an iterator to the beginning
    iterator begin() noexcept
    {
        return m_map.begin();
    }

    /// returns an iterator to the end
    iterator end() noexcept
    {
        return m_map.end();
    }

    /// returns an iterator to the beginning
    const_iterator begin() const noexcept
    {
        return m_map.begin();
    }

    /// returns an iterator to the end
    const_iterator end() const noexcept
    {
        return m_map.end();
    }

    /// returns an iterator to the beginning
    const_iterator cbegin() const noexcept
    {
        return m_map.cbegin();
    }

    /// returns an iterator to the end
    const_iterator cend() const noexcept
    {
        return m_map.cend();
    }

    /// returns a reverse iterator to the beginning
    reverse_iterator rbegin() noexcept
    {
        return m_map.rbegin();
    }

    /// returns a reverse iterator to the end
    reverse_iterator rend() noexcept
    {
        return m_map.rend();
    }

    /// returns a reverse iterator to the beginning
    const_reverse_iterator rbegin() const noexcept
    {
        return m_map.rbegin();
    }

    /// returns a reverse iterator to the end
    const_reverse_iterator rend() const noexcept
    {
        return m_map.rend();
    }

    /// returns a reverse iterator to the beginning
    const_reverse_iterator crbegin() const noexcept
    {
        return m_map.crbegin();
    }

    /// returns a reverse iterator to the end
    const_reverse_iterator crend() const noexcept
    {
        return m_map.crend();
    }


    /*
     * Capacity
     */

    /// checks whether the container is empty
    bool empty() const noexcept
    {
        return m_map.empty();
    }

    /// returns the number of elements
    size_type size() const noexcept
    {
        return m_map.size();
    }

    /// returns the maximum possible number of elements
    size_type max_size() const noexcept
    {
        return m_map.max_size();
    }


    /*
     * Modifiers
     */

    /// clears the contents
    void clear() noexcept
    {
        m_map.clear();
        m_keys.clear();
    }

    /// insert value
    std::pair<iterator, bool> insert(const value_type& value)
    {
        m_compare.add_key(value.first);
        return m_map.insert(value);
    }

    /// insert value
    template<class P>
    std::pair<iterator, bool> insert( P&& value )
    {
        m_compare.add_key(value.first);
        return m_map.insert(value);
    }

    /// insert value with hint
    iterator insert(const_iterator hint, const value_type& value)
    {
        m_compare.add_key(value.first);
        return m_map.insert(hint, value);
    }

    /// insert value with hint
    iterator insert(const_iterator hint, value_type&& value)
    {
        m_compare.add_key(value.first);
        return m_map.insert(hint, value);
    }

    /// insert value range
    template<class InputIt>
    void insert(InputIt first, InputIt last)
    {
        for (const_iterator it = first; it != last; ++it)
        {
            m_compare.add_key(it->first);
        }

        m_map.insert(first, last);
    }

    /// insert value list
    void insert(std::initializer_list<value_type> ilist)
    {
        for (auto value : ilist)
        {
            m_compare.add_key(value.first);
        }

        m_map.insert(ilist);
    }

    /// constructs element in-place
    template<class... Args>
    std::pair<iterator, bool> emplace(Args&& ... args)
    {
        typename fifo_map::value_type value(std::forward<Args>(args)...);
        m_compare.add_key(value.first);
        return m_map.emplace(std::move(value));
    }

    /// constructs element in-place with hint
    template<class... Args>
    iterator emplace_hint(const_iterator hint, Args&& ... args)
    {
        typename fifo_map::value_type value(std::forward<Args>(args)...);
        m_compare.add_key(value.first);
        return m_map.emplace_hint(hint, std::move(value));
    }

    /// remove element at position
    iterator erase(const_iterator pos)
    {
        m_compare.remove_key(pos->first);
        return m_map.erase(pos);
    }

    /// remove elements in range
    iterator erase(const_iterator first, const_iterator last)
    {
        for (const_iterator it = first; it != last; ++it)
        {
            m_compare.remove_key(it->first);
        }

        return m_map.erase(first, last);
    }

    /// remove elements with key
    size_type erase(const key_type& key)
    {
        size_type res = m_map.erase(key);

        if (res > 0)
        {
            m_compare.remove_key(key);
        }

        return res;
    }

    /// swaps the contents
    void swap(fifo_map& other)
    {
        std::swap(m_map, other.m_map);
        std::swap(m_compare, other.m_compare);
        std::swap(m_keys, other.m_keys);
    }


    /*
     * Lookup
     */

    /// returns the number of elements matching specific key
    size_type count(const Key& key) const
    {
        return m_map.count(key);
    }

    /// finds element with specific key
    iterator find(const Key& key)
    {
        return m_map.find(key);
    }

    /// finds element with specific key
    const_iterator find(const Key& key) const
    {
        return m_map.find(key);
    }

    /// returns range of elements matching a specific key
    std::pair<iterator, iterator> equal_range(const Key& key)
    {
        return m_map.equal_range(key);
    }

    /// returns range of elements matching a specific key
    std::pair<const_iterator, const_iterator> equal_range(const Key& key) const
    {
        return m_map.equal_range(key);
    }

    /// returns an iterator to the first element not less than the given key
    iterator lower_bound(const Key& key)
    {
        return m_map.lower_bound(key);
    }

    /// returns an iterator to the first element not less than the given key
    const_iterator lower_bound(const Key& key) const
    {
        return m_map.lower_bound(key);
    }

    /// returns an iterator to the first element greater than the given key
    iterator upper_bound(const Key& key)
    {
        return m_map.upper_bound(key);
    }

    /// returns an iterator to the first element greater than the given key
    const_iterator upper_bound(const Key& key) const
    {
        return m_map.upper_bound(key);
    }


    /*
     * Observers
     */

    /// returns the function that compares keys
    key_compare key_comp() const
    {
        return m_compare;
    }


    /*
     * Non-member functions
     */

    friend bool operator==(const fifo_map& lhs, const fifo_map& rhs)
    {
        return lhs.m_map == rhs.m_map;
    }

    friend bool operator!=(const fifo_map& lhs, const fifo_map& rhs)
    {
        return lhs.m_map != rhs.m_map;
    }

    friend bool operator<(const fifo_map& lhs, const fifo_map& rhs)
    {
        return lhs.m_map < rhs.m_map;
    }

    friend bool operator<=(const fifo_map& lhs, const fifo_map& rhs)
    {
        return lhs.m_map <= rhs.m_map;
    }

    friend bool operator>(const fifo_map& lhs, const fifo_map& rhs)
    {
        return lhs.m_map > rhs.m_map;
    }

    friend bool operator>=(const fifo_map& lhs, const fifo_map& rhs)
    {
        return lhs.m_map >= rhs.m_map;
    }

  private:
    /// the keys
    std::unordered_map<Key, std::size_t> m_keys;
    /// the comparison object
    Compare m_compare;
    /// the internal data structure
    internal_map_type m_map;
};

}

// specialization of std::swap
namespace std
{
template <class Key, class T, class Compare, class Allocator>
inline void swap(nlohmann::fifo_map<Key, T, Compare, Allocator>& m1,
                 nlohmann::fifo_map<Key, T, Compare, Allocator>& m2)
{
    m1.swap(m2);
}
}

#endif


//          Copyright Nathaniel Christen 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include "tile-server-select-dialog.h"

//?#include "styles.h"




#include <QApplication>

#include <QHBoxLayout>
#include <QVBoxLayout>

#include <QButtonGroup>
#include <QScrollArea>
#include <QFileDialog>
#include <QTabWidget>
#include <QSplitter>
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QCheckBox>
#include <QLineEdit>
#include <QGroupBox>

#include <QPlainTextEdit>
#include <QTextStream>

#include <QtMultimedia/QMediaPlayer>

#include <QPainter>
#include <QPushButton>
#include <QLabel>

//#include <QNetworkAccessManager>
//#include <QNetworkReply>

#include <QTableWidget>
#include <QGraphicsPixmapItem>

#include <QMessageBox>
#include <QDebug>
#include <QClipboard>

#include <QProcess>

#include <QGraphicsView>
#include <QScrollArea>

//#include <QTcpServer>
//#include <QNetworkAccessManager>

#include <QHeaderView>

#include <QMenu>
#include <QAction>

#include <QListWidget>

#include <QComboBox>

Tile_Server_Select_Dialog::Tile_Server_Select_Dialog(QWidget* parent)
  : QDialog(parent)
{
 button_box_ = new QDialogButtonBox(this);

 button_ok_ = new QPushButton("OK");
 button_proceed_ = new QPushButton("Edit");
 button_cancel_ = new QPushButton("Cancel");

 button_ok_->setDefault(false);
 button_ok_->setAutoDefault(false);

 button_proceed_->setDefault(false);
 button_proceed_->setAutoDefault(false);

 button_cancel_->setDefault(true);

 button_ok_->setEnabled(false);

 // // unless this is being embedded ...
 button_proceed_->setEnabled(false);
 button_cancel_->setText("Close");

 button_box_->addButton(button_ok_, QDialogButtonBox::AcceptRole);
 button_box_->addButton(button_proceed_, QDialogButtonBox::ApplyRole);
 button_box_->addButton(button_cancel_, QDialogButtonBox::RejectRole);

// button_ok_->setStyleSheet(basic_button_style_sheet_());
// button_proceed_->setStyleSheet(basic_button_style_sheet_());
// button_cancel_->setStyleSheet(basic_button_style_sheet_());

 connect(button_proceed_, SIGNAL(clicked()), this, SLOT(proceed()));
 connect(button_box_, SIGNAL(accepted()), this, SLOT(accept()));
 connect(button_box_, SIGNAL(rejected()), this, SLOT(cancel()));

 main_layout_ = new QVBoxLayout;
 form_layout_ = new QFormLayout;

 server_name_combo_box_ = new QComboBox(this);
 overlay_combo_box_ = new QComboBox(this);
 local_server_combo_box_ = new QComboBox(this);

 nlohmann::fifo_map<QString, QPair<QString, QString>> hosts_map {
  { "OpenStreetMap", {"", ""} },
  { "OpenStreetMap (French Style)", {"", ""} },
  { "Thunder Forest (cycle)", {"", ""} },
  { "Thunder Forest (transport)", {"", ""} },
  { "Thunder Forest (outdoors)", {"", ""} },
  { "Wikiocity", {"", ""} },
  { "cartodb", {"", ""} },
  { "Stamen (terrain)", {"", ""} },
  { "Stamen (watercolor)",{"", ""} },
  { "apfo", {"", ""} },
  { "Topomap", {"", ""} },
  { "ArcGIS", {"", ""} }
     };

 QStringList names;

 std::transform(hosts_map.begin(), hosts_map.end(),
   std::back_inserter(names),
   [](decltype(hosts_map)::value_type const& pair)
 {
  return pair.first;
 }
 );

 ////?   [](const std::map<QString, QPair<QString, QString>>::value_type& pair){return pair.first;});
 // [](QString, QPair<QString, QString>)

// using namespace std;
// QStringList keys;

// std::map<QString, QPair<QString, QString>> map_in;


 server_name_combo_box_->addItems(names);


 //   hosts = QStringList{"http://b.tile.openstreetmap.org/"};
 //   urls = QStringList{"%1/%2/%3.png"};

 //      hosts = QStringList{"https://tile.openstreetmap.org/"};
 //      urls = QStringList{"%1/%2/%3.png"};

 //         hosts = QStringList{"https://tile.openstreetmap.de/"};
 //         urls = QStringList{"%1/%2/%3.png"};

 //            hosts = QStringList{"https://tile.thunderforest.com/cycle/"};
 //            urls = QStringList{"%1/%2/%3.png"};

//       hosts = QStringList{"https://b.tile.openstreetmap.fr/hot/"};
//       urls = QStringList{"%1/%2/%3.png"};

 //      hosts = QStringList{"https://tile.thunderforest.com/transport/"};
 //      urls = QStringList{"%1/%2/%3.png"};

 //               hosts = QStringList{"https://api.wikiocity.com/r/raster/en/"};
 //               urls = QStringList{"%1/%2/%3.png"};

 //      hosts = QStringList{"https://tile.thunderforest.com/outdoors/"};
 //      urls = QStringList{"%1/%2/%3.png"};

 //?      hosts = QStringList{"https://cartodb-basemaps-a.global.ssl.fastly.net/light_all/"};
 //      urls = QStringList{"%1/%2/%3.png"};


       //https://tile.tracestrack.com/en/{z}/{x}/{y}.png
      // https://maps.geoapify.com/v1/tile/osm-bright-smooth/{z}/{x}/{y}.png

 //         hosts = QStringList{"https://tile.tracestrack.com/bus-route/"};
 //         urls = QStringList{"%1/%2/%3.png?key=bb0a959e5202daa5a0e923268a36b09e"};

 //   hosts = QStringList{"https://tile.tracestrack.com/base/"};
 //   urls = QStringList{"%1/%2/%3.png?key=bb0a959e5202daa5a0e923268a36b09e"};

 //         hosts = QStringList{"https://tile.tracestrack.com/en-name/"};
 //         urls = QStringList{"%1/%2/%3.png?key=bb0a959e5202daa5a0e923268a36b09e"};


    // status line or log to show/monitor network traffic,
    // including tile urls,

       // https://tile.waymarkedtrails.org/hiking/${z}/${x}/${y}.png
       // https://tile.waymarkedtrails.org/cycling/${z}/${x}/${y}.png
       // https://tile.tracestrack.com/bus-route/${z}/${x}/${y}.png
       // https://tile.tracestrack.com/subway-route/${z}/${x}/${y}.png
       // https://tile.tracestrack.com/train-route/${z}/${x}/${y}.png
       // https://tile.tracestrack.com/bicycle-route/${z}/${x}/${y}.png


 //   hosts = QStringList{"https://tile.waymarkedtrails.org/cycling/"};
 //            urls = QStringList{"%1/%2/%3.png"};




 //   hosts = QStringList{"https://stamen-tiles.a.ssl.fastly.net/terrain/"};
 //   urls = QStringList{"%1/%2/%3.png"};

 //      hosts = QStringList{"https://stamen-tiles.a.ssl.fastly.net/watercolor/"};
 //      urls = QStringList{"%1/%2/%3.jpg"};

 //   hosts = QStringList{"https://gis.apfo.usda.gov/arcgis/rest/services/NAIP/USDA_CONUS_PRIME/ImageServer/tile/"};
 //   urls = QStringList{"%1/%3/%2"};


 //   hosts = QStringList{"https://services.arcgisonline.com/arcgis/rest/services/World_Imagery/MapServer/tile/"};
 //   urls = QStringList{"%1/%3/%2"};

 // hosts = QStringList{"https://tile.opentopomap.org/"};
 // urls = QStringList{"%1/%2/%3.png"};



 overlay_combo_box_->addItems({"None", "Bus", "Train",
   "Cycle", "Hike"});

 local_server_combo_box_->addItems({"No Local Server",
   "QMT (port 6600)",
   "Late Nympth", "Adult", "Unknown/Unidentified"});

 api_key_ = new QLineEdit(this);
 api_key_->setPlaceholderText("(if needed for the server)");


 form_layout_->addRow("Name:", server_name_combo_box_);
 form_layout_->addRow("Overlays:", overlay_combo_box_);
 form_layout_->addRow("Local Server:", local_server_combo_box_);

 form_layout_->addRow("API Key:", api_key_);


 main_layout_->addLayout(form_layout_);

 main_layout_->addWidget(button_box_);

 setLayout(main_layout_);

 setWindowTitle("Select Tile Server");

}

//top_buttons_layout_ = new QHBoxLayout;

//take_screenshot_button_ = new QPushButton("Screenshot", this);

//activate_tcp_button_ = new QPushButton("Activate TCP", this);

//take_screenshot_button_->setStyleSheet(colorful_button_style_sheet_());
//activate_tcp_button_->setStyleSheet(colorful_button_style_sheet_());

//connect(take_screenshot_button_, SIGNAL(clicked()),
//  this, SLOT(handle_take_screenshot_requested()));

//connect(activate_tcp_button_, SIGNAL(clicked()),
//  this, SLOT(activate_tcp_requested()));

//top_buttons_layout_->addStretch();

//top_buttons_layout_->addWidget(activate_tcp_button_);

//top_buttons_layout_->addWidget(take_screenshot_button_);


Tile_Server_Select_Dialog::~Tile_Server_Select_Dialog()
{

}

void Tile_Server_Select_Dialog::cancel()
{
 Q_EMIT(rejected());
 Q_EMIT(canceled(this));
 Q_EMIT(rejected());
 close();
}

void Tile_Server_Select_Dialog::accept()
{
 Q_EMIT(accepted(this));
}
