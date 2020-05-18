#ifndef _VIDEOLOADER_H_
#define _VIDEOLOADER_H_
/*****************************************************************************
 * Filename		: video_loader.h
 * Author		: Edward Chuah
 * Organisation	: The University of Warwick, UK.
 * Date Created	: 7 May 2020
 * Description	: Video loader class.
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
#include "video_data.h"


class VideoLoader
{
public:
	VideoLoader();
	virtual ~VideoLoader();

	/**
	 * Method name		: run_on_1_processor
	 * Description		: Execute video data extraction on 1 processor
	 * Parameter list	: StringT, StringT, BoolT
	 * Return value		: void
	 */
	void run_on_1_processor( const CommonDataDefs::StringT &source_dir,
	 			 	 	 	 const CommonDataDefs::StringT &destination_dir,
							 CommonDataDefs::BoolT write_to_file = false );

	/**
	 * Method name		: run_on_4_processors
	 * Description		: Execute video data extraction on 4 processors
	 * Parameter list	: StringT, StringT, BoolT
	 * Return value		: void
	 */
	void run_on_4_processors( const CommonDataDefs::StringT &source_dir,
							  const CommonDataDefs::StringT &destination_dir,
							  CommonDataDefs::BoolT write_to_file = false );

	/**
	 * Method name		: run_on_8_processors
	 * Description		: Execute video data extraction on 8 processors
	 * Parameter list	: StringT, StringT, BoolT
	 * Return value		: void
	 */
	void run_on_8_processors( const CommonDataDefs::StringT &source_dir,
							  const CommonDataDefs::StringT &destination_dir,
							  CommonDataDefs::BoolT write_to_file = false );

	/**
	 * Method name		: run_on_16_processors
	 * Description		: Execute video data extraction on 16 processors
	 * Parameter list	: StringT, StringT, BoolT
	 * Return value		: void
	 */
	void run_on_16_processors( const CommonDataDefs::StringT &source_dir,
							   const CommonDataDefs::StringT &destination_dir,
							   CommonDataDefs::BoolT write_to_file = false );

	/**
	 * Method name		: get_video_count
	 * Description		:
	 * Parameter list	: void
	 * Return value		: IntT
	 */
	CommonDataDefs::IntT get_video_count() const;

	/**
	 * Method name		: get_video_properties
	 * Description		:
	 * Parameter list	: IntT, IntT, IntT, IntT
	 * Return value		: void
	 */
	void get_video_properties( const CommonDataDefs::IntT &index,
							   CommonDataDefs::IntT &frame_count,
							   CommonDataDefs::IntT &frame_height,
							   CommonDataDefs::IntT &frame_width );

	/**
	 * Method name		: get_videos_frames
	 * Description		:
	 * Parameter list	: IntT, IntT, IntT, UCharT
	 * Return value		: void
	 */
	void get_videos_frames( CommonDataDefs::IntT &number_of_videos,
							CommonDataDefs::IntT *&videos_frames_count_list,
							CommonDataDefs::IntT &number_of_frames_elements,
						    CommonDataDefs::UCharT *&videos_frames_data );

	/**
	 * Method name		: flatten_video_data
	 * Description		:
	 * Parameter list	: IntT
	 * Return value		: void
	 */
	void flatten_video_data( const CommonDataDefs::IntT &processor_id );


private:
	/**
	 * Method name		: read_files
	 * Description		: Read the paths and names for all the video files
	 * Parameter list	: StringT
	 * Return value		: BoolT
	 */
	CommonDataDefs::BoolT read_files( const CommonDataDefs::StringT &dir_path );

	/**
	 * Method name		: load_video_data
	 * Description		: Load_videos and extract all the frames in a video
	 * Parameter list	: StringVectorT, StringT, IntT, BoolT
	 * Return value		: void
	 */
	void load_video_data( const CommonDataDefs::StringVectorT &files_list,
					      const CommonDataDefs::StringT &destination_dir,
						  const CommonDataDefs::IntT &processor_id,
						  const CommonDataDefs::BoolT &write_data );

	/**
	 * Method name		: extract_video_frames
	 * Description		: Extract all the frames in a video file
	 * Parameter list	: StringT, VideoData
	 * Return value		: BoolT
	 */
	CommonDataDefs::BoolT extract_video_frames( const CommonDataDefs::StringT &file_name,
												VideoData &video_data );

	/**
	 * Method name		: processor_0_sends_data
	 * Description		: Processor ID 0 sends data to x number of processors
	 * Parameter list	: IntT, StringT, StringT
	 * Return value		: void
	 */
	void processor_0_sends_data( const CommonDataDefs::IntT &number_of_processors,
							   	 const CommonDataDefs::StringT &source_dir,
								 const CommonDataDefs::StringT &destination_dir );

	/**
	 * Method name		: processor_receives_data
	 * Description		: Processor n receives data for processing
	 * Parameter list	: IntT, StringVectorT, StringT
	 * Return value		: void
	 */
	void processor_receives_data( const CommonDataDefs::IntT &send_processor_id,
								  CommonDataDefs::StringVectorT &files_list,
								  CommonDataDefs::StringT &destination_dir );

	/**
	 * Method name		: return_extracted_video_data_to_processor_0
	 * Description		:
	 * Parameter list	: IntT
	 * Return value		: void
	 */
	void return_extracted_video_data_to_processor_0( const CommonDataDefs::IntT &processor_id );

	/**
	 * Method name		: processor_0_receives_extracted_video_data
	 * Description		:
	 * Parameter list	: IntT
	 * Return value		: void
	 */
	void processor_0_receives_extracted_video_data( const CommonDataDefs::IntT &number_of_processors );

private:
	CommonDataDefs::StringVectorT		m_Files_List;
	CommonDataDefs::VideoDataVectorT 	m_Video_Data_List;
	CommonDataDefs::UCharVectorT		m_Flattened_Video_Data_List;
	CommonDataDefs::IntVectorT			m_Videos_Frames_Count_List;
	CommonDataDefs::IntT				m_Total_Frames_Elements;

}; // end class VideoLoader

#endif // _VideoLoader_H


/*******************************
 * C interface wrapper *
 ******************************/
extern "C" {
	/**
	 * Method name		: vidl_new
	 * Description		: Instantiate object of class VideoLoader
	 * Parameter list	: void
	 * Return value		: VideoLoader
	 */
	VideoLoader* vidl_new()
	{
		return new VideoLoader();
	} // end vidl_new()

	/**
	 * Method name		: vidl_delete
	 * Description		: Destructor
	 * Parameter list	: VideoLoader, IntT, IntT
	 * Return value		: void
	 */
	void vidl_delete( VideoLoader *vidl,
					  CommonDataDefs::IntT *pointer_videos_frames_count_list,
					  CommonDataDefs::UCharT *pointer_videos_frames_data )
	{
		delete vidl;
		vidl = NULL;
		delete [] pointer_videos_frames_count_list;
		delete [] pointer_videos_frames_data;
	} // end vidl_delete()

	/**
	 * Method name		: vidl_run_on_1_processor
	 * Description		: Call VideoLoader class member function run_on_1_processor
	 * Parameter list	: VideoLoader, CharT, CharT
	 * Return value		: void
	 */
	 void vidl_run_on_1_processor( VideoLoader *vidl,
				  	  	  	  	   const CommonDataDefs::CharT *in_dir,
								   const CommonDataDefs::CharT *out_dir )
	{
		CommonDataDefs::StringT temp_in_dir( in_dir );
		CommonDataDefs::StringT temp_out_dir( out_dir );
		vidl->run_on_1_processor( temp_in_dir, temp_out_dir );
	} // end vidl_run_on_1_processor()

	/**
	 * Method name		: vidl_run_on_4_processors
	 * Description		: Call VideoLoader class member function run_on_4_processors
	 * Parameter list	: VideoLoader, CharT, CharT
	 * Return value		: void
	 */
	void vidl_run_on_4_processors( VideoLoader *vidl,
								   const CommonDataDefs::CharT *in_dir,
								   const CommonDataDefs::CharT *out_dir )
	{
		CommonDataDefs::StringT temp_in_dir( in_dir );
		CommonDataDefs::StringT temp_out_dir( out_dir );
		vidl->run_on_4_processors( temp_in_dir, temp_out_dir );
	} // end vidl_run_on_4_processors()

	/**
	 * Method name		: vidl_run_on_8_processors
	 * Description		: Call VideoLoader class member function run_on_8_processors
	 * Parameter list	: VideoLoader, CharT, CharT
	 * Return value		: void
	 */
	void vidl_run_on_8_processors( VideoLoader *vidl,
								   const CommonDataDefs::CharT *in_dir,
								   const CommonDataDefs::CharT *out_dir )
	{
		CommonDataDefs::StringT temp_in_dir( in_dir );
		CommonDataDefs::StringT temp_out_dir( out_dir );
		vidl->run_on_8_processors( temp_in_dir, temp_out_dir );
	} // end vidl_run_on_8_processors()

	/**
	 * Method name		: vidl_run_on_16_processors
	 * Description		: Call VideoLoader class member function run_on_16_processors
	 * Parameter list	: VideoLoader, CharT, CharT
	 * Return value		: void
	 */
	void vidl_run_on_16_processors( VideoLoader *vidl,
									const CommonDataDefs::CharT *in_dir,
									const CommonDataDefs::CharT *out_dir )
	{
		CommonDataDefs::StringT temp_in_dir( in_dir );
		CommonDataDefs::StringT temp_out_dir( out_dir );
		vidl->run_on_16_processors( temp_in_dir, temp_out_dir );
	} // end vidl_run_on_16_processors()

	void vidl_get_all_videos_frames( VideoLoader *vidl,
									 CommonDataDefs::IntT &number_of_videos,
									 CommonDataDefs::IntT *&videos_frames_count_list,
									 CommonDataDefs::IntT &number_of_frames_elements,
									 CommonDataDefs::UCharT *&videos_frames_data )
	{
		vidl->get_videos_frames( number_of_videos, videos_frames_count_list, number_of_frames_elements, videos_frames_data );
	} // end vidl_get_video_frame()
}
// end C interface wrapper
