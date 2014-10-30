//
// MainPage.xaml.h
// Declaration of the MainPage class.
//

#pragma once

#include "MainPage.g.h"

namespace Paintbin
{
	public ref class MainPage sealed
	{
		Windows::Foundation::Uri^ GetHomeUri() const
		{
			// TODO: Replace with your URL here.
			//return ref new Windows::Foundation::Uri(L"http://3deb8d2b.ngrok.com/paintbin");
			//return ref new Windows::Foundation::Uri(L"http://152.78.163.124:8000/");
			return ref new Windows::Foundation::Uri(L"http://152.78.163.124:8000/canvas/KVPFB02L8ZI79ZFR");
		}

	public:
		MainPage();

	protected:
		virtual void OnNavigatedTo(Windows::UI::Xaml::Navigation::NavigationEventArgs^ e) override;
		virtual void OnNavigatedFrom(Windows::UI::Xaml::Navigation::NavigationEventArgs^ e) override;

	private:
		Windows::Foundation::EventRegistrationToken _backPressedToken;

		void Browser_NavigationCompleted(Platform::Object^ sender, Windows::UI::Xaml::Controls::WebViewNavigationCompletedEventArgs^ e);
		void MainPage_BackPressed(Platform::Object^ sender, Windows::Phone::UI::Input::BackPressedEventArgs^ e);
		void HomeAppBarButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void BlueAppBarButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}
