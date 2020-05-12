/*****************************************************************************
 * Filename		: video_loader.cpp
 * Author		: Edward Chuah
 * Organisation	: The University of Warwick, UK.
 * Date Created	: 7 May 2020
 * Description	: Implementation of video loader class.
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
#include "video_loader.h"
#include <boost/filesystem.hpp>
#include "CommonDataDefs.h"
#include "mpi.h"
#include "opencv2/videoio.hpp"

using namespace CommonDataDefs;
using namespace std;
using namespace cv;
using namespace boost::filesystem;


VideoLoader::VideoLoader() {}

VideoLoader::~VideoLoader() {}


void VideoLoader::run_on_1_processor( const StringT &source_dir,
									  const StringT &destination_dir )
{
	read_files( source_dir );
	IntT processor_id = 0;
	load_video_data( m_Files_List, destination_dir, processor_id );
} // end run_on_1_processor()


void VideoLoader::run_on_4_processors( const StringT &source_dir,
									   const StringT &destination_dir )
{
	MPI_Init(NULL, NULL);

	int number_processors;
	MPI_Comm_size(MPI_COMM_WORLD, &number_processors); // get number of processors.

	int processor_id;
	MPI_Comm_rank(MPI_COMM_WORLD, &processor_id); // get the id of a processor.

	if( processor_id == 0 )
	{
		processor_0_sends_data( number_processors, source_dir, destination_dir );
		IntT files_partition_size = static_cast<IntT>( floor( m_Files_List.size() / number_processors ) );
		StringVectorT files_sub_list( m_Files_List.begin(), m_Files_List.begin()+files_partition_size );
		load_video_data( files_sub_list, destination_dir, processor_id );
	}

	if( processor_id == 1 )
	{
		StringVectorT files_list;
		StringT destination_dir;
		IntT send_processor_id = 0;
		processor_receives_data( send_processor_id, files_list, destination_dir );
		load_video_data( files_list, destination_dir, processor_id );
	}

	if( processor_id == 2 )
	{
		StringVectorT files_list;
		StringT destination_dir;
		IntT send_processor_id = 0;
		processor_receives_data( send_processor_id, files_list, destination_dir );
		load_video_data( files_list, destination_dir, processor_id );
	}

	if( processor_id == 3 )
	{
		StringVectorT files_list;
		StringT destination_dir;
		IntT send_processor_id = 0;
		processor_receives_data( send_processor_id, files_list, destination_dir );
		load_video_data( files_list, destination_dir, processor_id );
	}

	MPI_Finalize();
} // end run_on_4_processors()


void VideoLoader::run_on_8_processors( const StringT &source_dir,
									   const StringT &destination_dir )
{
	MPI_Init(NULL, NULL);

	int number_processors;
	MPI_Comm_size(MPI_COMM_WORLD, &number_processors); // get number of processors.

	int processor_id;
	MPI_Comm_rank(MPI_COMM_WORLD, &processor_id); // get the id of a processor.

	if( processor_id == 0 )
	{
		processor_0_sends_data( number_processors, source_dir, destination_dir );
		IntT files_partition_size = static_cast<IntT>( floor( m_Files_List.size() / number_processors ) );
		StringVectorT files_sub_list( m_Files_List.begin(), m_Files_List.begin()+files_partition_size );
		load_video_data( files_sub_list, destination_dir, processor_id );
	}

	if( processor_id == 1 )
	{
		StringVectorT files_list;
		StringT destination_dir;
		IntT send_processor_id = 0;
		processor_receives_data( send_processor_id, files_list, destination_dir );
		load_video_data( files_list, destination_dir, processor_id );
	}

	if( processor_id == 2 )
	{
		StringVectorT files_list;
		StringT destination_dir;
		IntT send_processor_id = 0;
		processor_receives_data( send_processor_id, files_list, destination_dir );
		load_video_data( files_list, destination_dir, processor_id );
	}

	if( processor_id == 3 )
	{
		StringVectorT files_list;
		StringT destination_dir;
		IntT send_processor_id = 0;
		processor_receives_data( send_processor_id, files_list, destination_dir );
		load_video_data( files_list, destination_dir, processor_id );
	}

	if( processor_id == 4 )
	{
		StringVectorT files_list;
		StringT destination_dir;
		IntT send_processor_id = 0;
		processor_receives_data( send_processor_id, files_list, destination_dir );
		load_video_data( files_list, destination_dir, processor_id );
	}

	if( processor_id == 5 )
	{
		StringVectorT files_list;
		StringT destination_dir;
		IntT send_processor_id = 0;
		processor_receives_data( send_processor_id, files_list, destination_dir );
		load_video_data( files_list, destination_dir, processor_id );
	}

	if( processor_id == 6 )
	{
		StringVectorT files_list;
		StringT destination_dir;
		IntT send_processor_id = 0;
		processor_receives_data( send_processor_id, files_list, destination_dir );
		load_video_data( files_list, destination_dir, processor_id );
	}

	if( processor_id == 7 )
	{
		StringVectorT files_list;
		StringT destination_dir;
		IntT send_processor_id = 0;
		processor_receives_data( send_processor_id, files_list, destination_dir );
		load_video_data( files_list, destination_dir, processor_id );
	}

	MPI_Finalize();
} // end run_on_8_processors()


void VideoLoader::run_on_16_processors( const StringT &source_dir,
										const StringT &destination_dir )
{
	MPI_Init(NULL, NULL);

	int number_processors;
	MPI_Comm_size(MPI_COMM_WORLD, &number_processors); // get number of processors.

	int processor_id;
	MPI_Comm_rank(MPI_COMM_WORLD, &processor_id); // get the id of a processor.

	if( processor_id == 0 )
	{
		processor_0_sends_data( number_processors, source_dir, destination_dir );
		IntT files_partition_size = static_cast<IntT>( floor( m_Files_List.size() / number_processors ) );
		StringVectorT files_sub_list( m_Files_List.begin(), m_Files_List.begin()+files_partition_size );
		load_video_data( files_sub_list, destination_dir, processor_id );
	}

	if( processor_id == 1 )
	{
		StringVectorT files_list;
		StringT destination_dir;
		IntT send_processor_id = 0;
		processor_receives_data( send_processor_id, files_list, destination_dir );
		load_video_data( files_list, destination_dir, processor_id );
	}

	if( processor_id == 2 )
	{
		StringVectorT files_list;
		StringT destination_dir;
		IntT send_processor_id = 0;
		processor_receives_data( send_processor_id, files_list, destination_dir );
		load_video_data( files_list, destination_dir, processor_id );
	}

	if( processor_id == 3 )
	{
		StringVectorT files_list;
		StringT destination_dir;
		IntT send_processor_id = 0;
		processor_receives_data( send_processor_id, files_list, destination_dir );
		load_video_data( files_list, destination_dir, processor_id );
	}

	if( processor_id == 4 )
	{
		StringVectorT files_list;
		StringT destination_dir;
		IntT send_processor_id = 0;
		processor_receives_data( send_processor_id, files_list, destination_dir );
		load_video_data( files_list, destination_dir, processor_id );
	}

	if( processor_id == 5 )
	{
		StringVectorT files_list;
		StringT destination_dir;
		IntT send_processor_id = 0;
		processor_receives_data( send_processor_id, files_list, destination_dir );
		load_video_data( files_list, destination_dir, processor_id );
	}

	if( processor_id == 6 )
	{
		StringVectorT files_list;
		StringT destination_dir;
		IntT send_processor_id = 0;
		processor_receives_data( send_processor_id, files_list, destination_dir );
		load_video_data( files_list, destination_dir, processor_id );
	}

	if( processor_id == 7 )
	{
		StringVectorT files_list;
		StringT destination_dir;
		IntT send_processor_id = 0;
		processor_receives_data( send_processor_id, files_list, destination_dir );
		load_video_data( files_list, destination_dir, processor_id );
	}

	if( processor_id == 8 )
	{
		StringVectorT files_list;
		StringT destination_dir;
		IntT send_processor_id = 0;
		processor_receives_data( send_processor_id, files_list, destination_dir );
		load_video_data( files_list, destination_dir, processor_id );
	}

	if( processor_id == 9 )
	{
		StringVectorT files_list;
		StringT destination_dir;
		IntT send_processor_id = 0;
		processor_receives_data( send_processor_id, files_list, destination_dir );
		load_video_data( files_list, destination_dir, processor_id );
	}

	if( processor_id == 10 )
	{
		StringVectorT files_list;
		StringT destination_dir;
		IntT send_processor_id = 0;
		processor_receives_data( send_processor_id, files_list, destination_dir );
		load_video_data( files_list, destination_dir, processor_id );
	}

	if( processor_id == 11 )
	{
		StringVectorT files_list;
		StringT destination_dir;
		IntT send_processor_id = 0;
		processor_receives_data( send_processor_id, files_list, destination_dir );
		load_video_data( files_list, destination_dir, processor_id );
	}

	if( processor_id == 12 )
	{
		StringVectorT files_list;
		StringT destination_dir;
		IntT send_processor_id = 0;
		processor_receives_data( send_processor_id, files_list, destination_dir );
		load_video_data( files_list, destination_dir, processor_id );
	}

	if( processor_id == 13 )
	{
		StringVectorT files_list;
		StringT destination_dir;
		IntT send_processor_id = 0;
		processor_receives_data( send_processor_id, files_list, destination_dir );
		load_video_data( files_list, destination_dir, processor_id );
	}

	if( processor_id == 14 )
	{
		StringVectorT files_list;
		StringT destination_dir;
		IntT send_processor_id = 0;
		processor_receives_data( send_processor_id, files_list, destination_dir );
		load_video_data( files_list, destination_dir, processor_id );
	}

	if( processor_id == 15 )
	{
		StringVectorT files_list;
		StringT destination_dir;
		IntT send_processor_id = 0;
		processor_receives_data( send_processor_id, files_list, destination_dir );
		load_video_data( files_list, destination_dir, processor_id );
	}

	MPI_Finalize();
} // end run_on_16_processors()


/***************************
  PRIVATE MEMBER FUNCTIONS
 ***************************/
BoolT VideoLoader::read_files( const StringT &dir_path )
{
	path p( dir_path );
	if( !exists( p ) || !is_directory( p ) )
	{
		cout << "Not a directory.\n";
		return false;
	}

	cout << "Directory " << p << "\n";
	directory_iterator end_itr;
	for( directory_iterator itr( p ); itr != end_itr; ++itr )
	{
		m_Files_List.push_back( itr->path().string() );
	}
	return true;
} //end read_files()


void VideoLoader::load_video_data( const StringVectorT &files_list,
								   const StringT &destination_dir,
						 		   const IntT &processor_id,
								   BoolT write_data )
{
	cout << "Processor ID " << processor_id << ": load " << files_list.size()
		 << " videos into array.\n";

	VideoDataVectorT video_data_list;
	for( IntT i=0; i<files_list.size(); ++i )
	{
		VideoData video_data;
		extract_video_frames( files_list.at( i ), video_data );
		video_data_list.push_back( video_data );
	}

	if( !write_data )
	{
		return;
	}

	for( IntT i=0; i<video_data_list.size(); ++i )
	{
		video_data_list.at( i ).write_data_to_local( destination_dir );
	}
} // end load_video_data()


BoolT VideoLoader::extract_video_frames( const StringT &file_name,
										 VideoData &video_data )
{
	VideoCapture cap;
	cap.open( file_name );
	if( !cap.isOpened() )
	{
		cout << "Error opening video file. Exiting now.\n";
		return false;
	}

	IntT frame_count = cap.get( CAP_PROP_FRAME_COUNT );
	video_data.set_file_name( file_name );
	video_data.set_frame_count( frame_count );
	video_data.set_frame_height( cap.get( CAP_PROP_FRAME_HEIGHT ) );
	video_data.set_frame_width( cap.get( CAP_PROP_FRAME_WIDTH ) );
	for( IntT i=0; i<frame_count; ++i )
	{
		MatT frame;
		cap.read( frame );
		video_data.set_frame( frame );
	}

	cap.release();
	return true;
} // end extract_video_frames()


void VideoLoader::processor_0_sends_data( const IntT &number_of_processors,
										  const StringT &source_dir,
										  const StringT &destination_dir )
{
	IntT destination_dir_length = destination_dir.size();
	for( IntT i=1; i<number_of_processors; ++i )
	{
		MPI_Send( &destination_dir_length, 1, MPI_INT, i, 0, MPI_COMM_WORLD );
		MPI_Send( destination_dir.data(), destination_dir_length, MPI_CHAR, i, 0, MPI_COMM_WORLD );
	}

	read_files( source_dir );
	IntT files_partition_size = static_cast<IntT>( floor( m_Files_List.size() / number_of_processors ) );
	IntT files_remainder = m_Files_List.size() % number_of_processors;
	for( IntT i=1; i<number_of_processors-1; ++i )
	{
		MPI_Send( &files_partition_size, 1, MPI_INT, i, 0, MPI_COMM_WORLD );
		for( IntT j=files_partition_size*i; j<files_partition_size*(i+1); ++j )
		{
			IntT file_length = m_Files_List.at( j ).size();
			MPI_Send( &file_length, 1, MPI_INT, i, 0, MPI_COMM_WORLD );
			MPI_Send( m_Files_List.at( j ).data(), file_length, MPI_CHAR, i, 0, MPI_COMM_WORLD );
		}
	}

	IntT last_processor_id = number_of_processors - 1;
	IntT files_last_partition_size = files_partition_size + files_remainder;
	MPI_Send( &files_last_partition_size, 1, MPI_INT, last_processor_id, 0, MPI_COMM_WORLD );
	IntT start_index = files_partition_size*last_processor_id;
	for( IntT i=start_index; i<m_Files_List.size(); ++i )
	{
		IntT file_length = m_Files_List.at( i ).size();
		MPI_Send( &file_length, 1, MPI_INT, last_processor_id, 0, MPI_COMM_WORLD );
		MPI_Send( m_Files_List.at( i ).data(), file_length, MPI_CHAR, last_processor_id, 0, MPI_COMM_WORLD );
	}
} // end processor_sends_data()


void VideoLoader::processor_receives_data( const IntT &send_processor_id,
										   StringVectorT &files_list,
										   StringT &destination_dir )
{
	MPI_Status s;
	IntT destination_dir_length = 0;
	MPI_Recv( &destination_dir_length, 1, MPI_INT, send_processor_id, 0, MPI_COMM_WORLD, &s );

	CharVectorT temp_dir( destination_dir_length );
	MPI_Recv( temp_dir.data(), destination_dir_length, MPI_CHAR, send_processor_id, 0, MPI_COMM_WORLD, &s );
	destination_dir.assign( temp_dir.begin(), temp_dir.end() );

	IntT files_partition_size = 0;
	MPI_Recv( &files_partition_size, 1, MPI_INT, send_processor_id, 0, MPI_COMM_WORLD, &s );

	for( IntT i=0; i<files_partition_size; ++i )
	{
		IntT file_size = 0;
		MPI_Recv( &file_size, 1, MPI_INT, send_processor_id, 0, MPI_COMM_WORLD, &s );

		CharVectorT temp( file_size );
		MPI_Recv(  temp.data(), file_size, MPI_CHAR, send_processor_id, 0, MPI_COMM_WORLD, &s );
		StringT file_name;
		file_name.assign( temp.begin(), temp.end() );
		files_list.push_back( file_name );
	}
} // end processor_receives_data()
