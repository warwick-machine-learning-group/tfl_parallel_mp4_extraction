/*****************************************************************************
 * Filename		: video_data.cpp
 * Author		: Edward Chuah
 * Organisation	: The University of Warwick, UK.
 * Date Created	: 1 May 2020
 * Description	: Implementation of video data class.
 *
 * Version				: See release notes.
 * Owner				: To be included.
 * Copyright(c) 2020	: To be included.
 *
 * Change Log:
 * Date			Author				Change Description
 * ====         ======				==================
 *
 ****************************************************************************/
#include "video_data.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <boost/filesystem.hpp>
#include "opencv2/imgcodecs.hpp"

using namespace CommonDataDefs;
using namespace std;
using namespace boost::filesystem;
using namespace cv;


VideoData::VideoData()
: m_File_Name( "" ),
  m_Frame_Count( 0 ),
  m_Frame_Height( 0 ),
  m_Frame_Width( 0 )
{}

VideoData::VideoData( const StringT &file_name,
					  const IntT &frame_count,
					  const IntT &frame_height,
					  const IntT &frame_width )
: m_File_Name( file_name ),
  m_Frame_Count( frame_count ),
  m_Frame_Height( frame_height ),
  m_Frame_Width( frame_width )
{}

VideoData::~VideoData()
{}


void VideoData::set_file_name( const StringT &file_name )
{
	IntT start_position = file_name.rfind( "/" );
	if( start_position != StringT::npos )
	{
		m_File_Name.assign( file_name.begin()+start_position+1, file_name.end() );
	}
} // end set_file_name()


void VideoData::set_frame_count( const IntT &frame_count )
{
	m_Frame_Count = frame_count;
} // end set_frame_count()


void VideoData::set_frame_height( const IntT &frame_height )
{
	m_Frame_Height = frame_height;
} // end set_frame_height()


void VideoData::set_frame_width( const IntT &frame_width )
{
	m_Frame_Width = frame_width;
} // end set_frame_width()


void VideoData::set_frame( const MatT &frame )
{
	m_Frame_List.push_back( frame );
} // end set_frame()


StringT VideoData::get_file_name() const
{
	return m_File_Name;
} // end get_file_name()


IntT VideoData::get_frame_count() const
{
	return m_Frame_Count;
} // end get_frame_count()


IntT VideoData::get_frame_height() const
{
	return m_Frame_Height;
} // end get_frame_height()


IntT VideoData::get_frame_width() const
{
	return m_Frame_Width;
} // end get_frame_width()


BoolT VideoData::get_frame( const IntT &index,
							MatT &frame )
{
	if( index >= m_Frame_List.size() )
	{
		return false;
	}

	frame = m_Frame_List.at( index );
	return true;
} // end get_frame()


BoolT VideoData::write_data_to_local( const StringT &dir_path )
{
	path temp_dir = complete( path( dir_path ) );
	if( !exists( temp_dir ) || !is_directory( temp_dir ) )
	{
		create_directory( temp_dir );
	}

	StringT file_dir = dir_path + "/" + m_File_Name;
	temp_dir = complete( path( file_dir ) );
	if( !exists( temp_dir ) || !is_directory( temp_dir ) )
	{
		create_directory( temp_dir );
	}

	for( IntT i=0; i<m_Frame_List.size(); ++i )
	{
		stringstream ss;
		ss << i;
		StringT frame_name = file_dir + "/" + ss.str() + ".jpg";
		if( !imwrite( frame_name, m_Frame_List.at( i ) ) )
		{
			return false;
		}
	}

	return true;
} // end write_data_to_local()
