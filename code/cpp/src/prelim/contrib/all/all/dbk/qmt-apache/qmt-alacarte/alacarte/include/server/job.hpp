/**
 *  This file is part of alaCarte.
 *
 *  alaCarte is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Affero General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  alaCarte is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU Affero General Public License for more details.
 *
 *  You should have received a copy of the GNU Affero General Public License
 *  along with alaCarte. If not, see <http://www.gnu.org/licenses/>.
 *
 *  Copyright alaCarte 2012-2013 Simon Dreher, Florian Jacob, Tobias Kahlert, Patrick Niklaus, Bernhard Scheirle, Lisa Winter
 *  Maintainer: Bernhard Scheirle
 **/

#pragma once
#ifndef JOB_HPP
#define JOB_HPP

#include "settings.hpp"

#include "server/tile_identifier.hpp"
#include "utils/statistic.hpp"


class MetaIdentifier;
class Tile;
class RequestManager;
class Configuration;
class Stylesheet;
class HttpRequest;
class RenderCanvas;

#ifdef QT_HOOK
class Single_Job_Context;
class Job_Context;

class QMT_Tile_Object_Coordinates;

//?#include <QString>

#endif


/**
 * @brief Abstract Class which computes Tiles by a given TileIdentifier.
 **/
class Job
{
#ifdef QT_HOOK

 QMT_Tile_Object_Coordinates* coordinates_save_info_;

 Single_Job_Context* single_job_context_;

public:

 Single_Job_Context* single_job_context()
 { return single_job_context_; }

 void set_save_info(QMT_Tile_Object_Coordinates* coords)
 {
  coordinates_save_info_ = coords;
 }

#endif

public:


	Job(const shared_ptr<MetaIdentifier>& mid,
		const shared_ptr<Configuration>& config,
		const shared_ptr<RequestManager>& manager,
		const shared_ptr<RenderCanvas>& canvas);

	void process();
	void deliver();
	void addRequest(const shared_ptr<HttpRequest>& req, const shared_ptr<TileIdentifier>& id)
	{
		requests[*id].push_back(req);
	}
	bool isEmpty() { return empty; }
	const shared_ptr<MetaIdentifier>& getIdentifier() { return mid; }

private:
	TESTABLE shared_ptr<Tile> computeEmpty();
	TESTABLE FixedRect computeRect(const shared_ptr<TileIdentifier>& ti);
	TESTABLE FixedRect computeRect(const shared_ptr<MetaIdentifier>& ti);
	bool initTiles();

private:
	//! RequestManager which holds all important components.
	shared_ptr<RequestManager> manager;
	//! supplied by worker thread
	shared_ptr<RenderCanvas> canvas;
	shared_ptr<Configuration> config;
	shared_ptr<MetaIdentifier> mid;
	bool empty;
	bool cached;
	//! initialized by initTiles
	std::vector<shared_ptr<Tile>> tiles;
	boost::unordered_map<TileIdentifier, std::list<shared_ptr<HttpRequest>>> requests;

	//! used to generate statistics
	shared_ptr<Statistic::JobMeasurement> measurement;
};

#endif
