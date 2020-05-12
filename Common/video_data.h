#ifndef _VIDEODATA_H_
#define _VIDEODATA_H_
/*****************************************************************************
 * Filename		: video_data.h
 * Author		: Edward Chuah
 * Organisation	: The University of Warwick, UK.
 * Date Created	: 1 May 2020
 * Description	: Video data class providing set and get video data functions.
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
#include "CommonDataDefs.h"


class VideoData
{
public:
	VideoData();
	VideoData( const CommonDataDefs::StringT &file_name,
			   const CommonDataDefs::IntT &frame_count,
			   const CommonDataDefs::IntT &frame_height,
			   const CommonDataDefs::IntT &frame_width );
	virtual ~VideoData();

	/**
	 * Method name		: set_file_name
	 * Description		: Set video file name
	 * Parameter list	: StringT
	 * Return value		: void
	 */
	void set_file_name( const CommonDataDefs::StringT &file_name );
	/**
	 * Method name		: set_frame_count
	 * Description		: Set video frame count
	 * Parameter list	: IntT
	 * Return value		: void
	 */
	void set_frame_count( const CommonDataDefs::IntT &frame_count );

	/**
	 * Method name		: set_frame_height
	 * Description		: Set video frame height
	 * Parameter list	: IntT
	 * Return value		: void
	 */
	void set_frame_height( const CommonDataDefs::IntT &frame_height );

	/**
	 * Method name		: setFrameWidth
	 * Description		: Set video frame width
	 * Parameter list	: IntT
	 * Return value		: void
	 */
	void set_frame_width( const CommonDataDefs::IntT &frame_width );

	/**
	 * Method name		: set_frame
	 * Description		: Store a video frame
	 * Parameter list	: MatT
	 * Return value		: void
	 */
	void set_frame( const CommonDataDefs::MatT &frame );

	/**
	 * Method name		: get_file_name
	 * Description		: Get name of file
	 * Parameter list	: void
	 * Return value		: StringT
	 */
	CommonDataDefs::StringT get_file_name() const;
	/**
	 * Method name		: get_frame_count
	 * Description		: Get number of frames
	 * Parameter list	: void
	 * Return value		: IntT
	 */
	CommonDataDefs::IntT get_frame_count() const;

	/**
	 * Method name		: get_frame_height
	 * Description		: Get height of video frame
	 * Parameter list	: void
	 * Return value		: IntT
	 */
	CommonDataDefs::IntT get_frame_height() const;

	/**
	 * Method name		: get_frame_width
	 * Description		: Get width of video frame
	 * Parameter list	: void
	 * Return value		: IntT
	 */
	CommonDataDefs::IntT get_frame_width() const;

	/**
	 * Method name		: get_frame
	 * Description		: Get a video frame
	 * Parameter list	: IntT, MatT
	 * Return value		: BoolT
	 */
	CommonDataDefs::BoolT get_frame( const CommonDataDefs::IntT &index,
									 CommonDataDefs::MatT &frame );

	/**
	 * Method name		: write_data_to_local
	 * Description		: Write video data to a local disk
	 * Parameter list	: StringT
	 * Return value		: BoolT
	 */
	CommonDataDefs::BoolT write_data_to_local( const CommonDataDefs::StringT &dir_path );


private:
	CommonDataDefs::StringT		m_File_Name;
	CommonDataDefs::IntT 		m_Frame_Count;
	CommonDataDefs::IntT 		m_Frame_Height;
	CommonDataDefs::IntT 		m_Frame_Width;
	CommonDataDefs::MatVectorT	m_Frame_List;

}; // end class VideoData

#endif // _VideoData_H_
