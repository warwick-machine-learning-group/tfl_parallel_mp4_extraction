/*****************************************************************************
 * Filename		: load_video.cpp
 * Author		: Edward Chuah
 * Organisation	: The University of Warwick, UK.
 * Date Created	: 1 May 2020
 * Description	: Test stub for loading videos.
 *
 * Copyright(c)	: GPL 3.0 (https://www.gnu.org/licenses/gpl-3.0.en.html)
 *
 * Change Log:
 * Date			Author				Change Description
 * ====         ======				==================
 *
 ****************************************************************************/
#include <iostream>
#include "CommonDataDefs.h"
#include "video_loader.h"

using namespace CommonDataDefs;
using namespace std;


IntT main( IntT argc, CharT *argv[] )
{
	if( argc == 1 )
	{
		cout << "Video data loader\n"
				"1. To execute on a single processor, specify vidext -single "
				"[video_source_directory] [video_destination_directory]\n"
				"2. To execute on multiple processors, specify mpirun -np "
				"[number_of_processors] vidext -multiple [number of procesors] "
				"[video_source_directory] [video_destination_directory]\n";
		return -1;
	}

	StringVectorT arguments;
	for( IntT i=1; i<argc; ++i )
	{
		StringT arg( argv[ i ] );
		arguments.push_back( arg );
	}

	VideoLoader video_loader;

	if( arguments.at( 0 ).compare( "-single" ) == 0 && arguments.size() == 3 )
	{
		video_loader.run_on_1_processor( arguments.at( 1 ).c_str(), arguments.at( 2 ).c_str() );
		return 0;
	}

	if( arguments.at( 0 ).compare( "-multiple" ) == 0 && arguments.size() == 4 )
	{
		IntT number_of_processors = atoi( arguments.at( 1 ).c_str() );
		IntVectorT videos_frames_count_list;
		UCharVectorT videos_frames_data;
		if( number_of_processors == 4 )
		{
			video_loader.run_on_4_processors( arguments.at( 2 ), arguments.at( 3 ) );
			video_loader.get_videos_frames( videos_frames_count_list, videos_frames_data );
			cout << "Number of videos: " << videos_frames_count_list.size() << "\n";
			cout << "Number of frames elements: " << videos_frames_data.size() << "\n";
			return 0;
		}

		if( number_of_processors == 8 )
		{
			video_loader.run_on_8_processors( arguments.at( 2 ), arguments.at( 3 ) );
			video_loader.get_videos_frames( videos_frames_count_list, videos_frames_data );
			cout << "Number of videos: " << videos_frames_count_list.size() << "\n";
			cout << "Number of frames elements: " << videos_frames_data.size() << "\n";
			return 0;
		}

		if( number_of_processors == 16 )
		{
			video_loader.run_on_16_processors( arguments.at( 2 ), arguments.at( 3 ) );
			video_loader.get_videos_frames( videos_frames_count_list, videos_frames_data );
			cout << "Number of videos: " << videos_frames_count_list.size() << "\n";
			cout << "Number of frames elements: " << videos_frames_data.size() << "\n";
			return 0;
		}

		return 0;
	}

	cout << "Wrong number of arguments given.\n";
	return 0;
} // end main()
