#include "opencv2/core/mat.hpp"
#include "video_loader.h"
#include "CommonDataDefs.h"

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
	 * Parameter list	: VideoLoader, IntT
	 * Return value		: void
	 */
	void vidl_delete( VideoLoader *vidl,
					  CommonDataDefs::UCharT *frame_data )
	{
		delete vidl;
		vidl = NULL;
		delete [] frame_data;
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

	void vidl_get_video_count( VideoLoader *vidl,
							   CommonDataDefs::IntT &video_count )
	{
		video_count = vidl->get_video_count();
	} // end vidl_get_video_count()

	void vidl_get_video_properties( VideoLoader *vidl,
									const CommonDataDefs::IntT &video_index,
									CommonDataDefs::IntT &frame_count,
									CommonDataDefs::IntT &frame_height,
									CommonDataDefs::IntT &frame_width )
	{
		vidl->get_video_properties( video_index, frame_count, frame_height, frame_width );
	} // end vidl_get_video_properties()

	void vidl_get_video_frame( VideoLoader *vidl,
							   const CommonDataDefs::IntT &video_index,
							   const CommonDataDefs::IntT &frame_index,
							   CommonDataDefs::UCharT *&frame_data )
	{
		CommonDataDefs::MatT frame;
		vidl->get_video_frame( video_index, frame_index, frame );
		/*frame_data = new CommonDataDefs::UCharT[ frame.total() ];
		memcpy( frame_data, frame.data, frame.total() * sizeof( CommonDataDefs::UCharT ) );*/
	} // end vidl_get_video_frame()
}
